double calculateInternal_Rate_Return(double initialCost, double expectedRevenue, int num_Periods)
{
    double rate = 0.0;
    double precision = 0.00001;
    double net_present_value = 0.0;
    double high = 1.0;
    double low = 0.0;
    while (high - low > precision)
    {
        rate = (high + low) / 2;
        net_present_value = initialCost;
        for (int i = 0; i < num_Periods; i++)
        {
            net_present_value += expectedRevenue / pow(1 + rate, i + 1);
        }
        if (net_present_value > 0)
        {
            low = rate;
        }
        else
        {
            high = rate;
        }
    }
    return rate;
}