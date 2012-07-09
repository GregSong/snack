#ifndef _SNACK_DEBUG_H
#define _SNACK_DEBUG_H

#ifdef _DEBUG_
#define DEBUG_PRINT_FUNC() do{std::cout<<__FILE__<<":"<<__LINE__<<"\t->"<<__FUNCTION__<<std::endl;}while(0)
#else
#define DEBUG_PRINT_FUNC() 
#endif // _DEBUG_
#endif // _SNACK_DEBUG_H
