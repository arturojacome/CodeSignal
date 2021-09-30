int centuryFromYear(int year) {
    
    int century = 0;
    int centuryRes = 0;
    
    century = year/100;
    centuryRes = year % 100;
    
    if(centuryRes > 0)
    {
        century = century + 1;
        return century;
    }
    else 
    {
        return century;
    }
    
    return century;
    
}
