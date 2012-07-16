template<typename T1, typename T2>
Int Manager<typename T1, typename T2>::Register(IN const T1& key, IN const T2& value)
{ 
    Bool ret_code = SNACK_SUCCESS;
    if(members_.find(key) == members_.end() )
    {
        members_.insert(pair<T1, T2>(key, value));
    } else {
        // log error
        ret_code = SNACK_FAILURE;
    }
    return ret_code;
}

template<typename T1, typename T2>
map<T1,T2>::iterator& Manager<T1, T2>::operator[](const T1& key)
{ 
    return members._find(key) != members_.end(); 
}

