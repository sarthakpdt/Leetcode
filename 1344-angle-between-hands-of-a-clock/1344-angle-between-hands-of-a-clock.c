double angleClock(int hour, int minutes) {
    double diff=fabs((30*(hour%12))-(5.5*minutes));
    double res=fmin(diff,360-diff);
    return res;
}