 time_t tt=time(NULL);
  tm* t=localtime(&tt);
  cout<<"Year: "<<t->tm_year+1900<<
    " Month: "<<t->tm_mon+1<<
    " Day: "<<t->tm_mday<<
    " Hour: "<<t->tm_hour<<
    " Minute: "<<t->tm_min<<
    " Second: "<<t->tm_sec<<endl;
  clock(a,t->tm_hour,t->tm_min,t->tm_sec);
  return 0;
