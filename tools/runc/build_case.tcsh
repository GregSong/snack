#!/bin/tcsh -fx

if ( $# < 2 ) then
    echo '\033[31mWorng Argument\!\!\!\033[m'
    echo '\033[32mUsage:'
    echo "\t$0 CASE_NAME COMMENTS\033[m"
    exit 1
endif

set CASE_NAME = $1
set COMMENTS = $argv[1-]

set UCASE_NAME = `echo $CASE_NAME | tr "[a-z]" "[A-Z]"`
set LCASE_NAME = `echo $CASE_NAME | tr "[A-Z]" "[a-z]"`
set FUCASE_NAME = `echo $CASE_NAME | sed -e 's/^[a-z]/\U&/g'`

# Check config file
#
if ( ! -e case.conf ) then
    echo "sample 1 case template" >> case.conf
endif

# Get new case id 
#
egrep "\'^$LCASE_NAME\'" case.conf
if $? != 0 then
    @ NO = `tail -n 1 case.conf | awk '{print $2;}'`
else
    echo '\033[31mAlready have this case!\033[m'
    exit 1
endif
@ NO = $NO + 1
echo $NO


# Create folder
#
set work_dir = cases/$LCASE_NAME
if ( -e $work_dir ) then
    echo "\033[32mPlease check folder $work_dir\033[m"
    exit 1
endif

cp -r cases/sample $work_dir

# Update makefile
#
cat $work_dir/makefile | sed -e 's/sample/'$LCASE_NAME'/g' >! $work_dir/makefile.tmp
mv $work_dir/makefile.tmp $work_dir/makefile 

# Update header file
#
cat $work_dir/sample.h | sed -e 's/SAMPLE 1/'$UCASE_NAME' '$NO'/g' -e 's/sample/'$LCASE_NAME'/g' -e 's/Sample/'$FUCASE_NAME'/g' -e 's/SAMPLE/'$UCASE_NAME'/g'  > $work_dir/$LCASE_NAME.h.tmp
mv $work_dir/$LCASE_NAME.h.tmp $work_dir/$LCASE_NAME.h

# Update .cc file
#
cat $work_dir/sample.cc | sed -e 's/sample/'$LCASE_NAME'/g' -e 's/Sample/'$FUCASE_NAME'/g' -e 's/SAMPLE/'$UCASE_NAME'/g' > $work_dir/$LCASE_NAME.cc.tmp
mv $work_dir/$LCASE_NAME.cc.tmp $work_dir/$LCASE_NAME.cc

# Update main.cc
#
cat $work_dir/main.cc | sed -e 's/sample/'$LCASE_NAME'/g' -e 's/Sample/'$FUCASE_NAME'/g' -e 's/SAMPLE/'$UCASE_NAME'/g' > $work_dir/main.cc.tmp
mv $work_dir/main.cc.tmp $work_dir/main.cc

# CLEAN tmp
rm $work_dir/sample.h $work_dir/sample.cc 

# Update case.conf
echo $CASE_NAME" "$NO" "$COMMENTS >> case.conf

