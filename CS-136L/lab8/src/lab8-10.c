/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// global constants
#define MIN_TEMP 10.0
#define MAX_TEMP 50.0
#define MIN_TEMP_DIFF 5.0

// TODO: write your function here
void detectAnomalies(const char *sensorData, const char *anomalies)
{
    FILE *dataFile = fopen(sensorData, "r");
    FILE *anomaliesFile = fopen(anomalies, "w");

    if(dataFile != NULL && anomaliesFile != NULL)
    {
        double min;
        double max;
        while(fscanf(dataFile, "%lf,%lf", &min, &max) == 2)
        {
            if(min < MIN_TEMP || min > MAX_TEMP)
            {
                fprintf(anomaliesFile, "Min Temp: %.2lf (Out of range)\n", min);
            }
            if(max < MIN_TEMP || max > MAX_TEMP)
            {
                fprintf(anomaliesFile, "Max Temp: %.2lf (Out of range)\n", max);
            }
            if(min <= max && (max - min) < MIN_TEMP_DIFF)
            {
                fprintf(anomaliesFile, "Min Temp: %.2lf, Max Temp: %.2lf (Small range)\n", min, max);
            }
            if(min > max)
            {
                fprintf(anomaliesFile, "Min Temp: %.2lf, Max Temp: %.2lf (Reversed range)\n", min, max);
            }
        }
    }

    if(dataFile != NULL)
    {
        fclose(dataFile);
    }
    if(anomaliesFile != NULL)
    {
        fclose(anomaliesFile);
    }
}