/**
 * Driver: <First Name> <Last Name>
 * Navigator: <First Name> <Last Name>
 **/

// header files
#include <stdio.h>

// global definitions
#define DATA_SIZE 10

// TODO: define the enum here
typedef enum WeatherCondition
{
    SUNNY,
    RAINY,
    CLOUDY,
    SNOWY,
    NUM_CONDITIONS
} WeatherCondition;


// TODO: define the Weather here
typedef struct Weather
{
    float temperature;
    float humidity;
    WeatherCondition condition;
} Weather;


// TODO: write the function prototype here
const char* getWeatherText(WeatherCondition condition);


// main program
int main()
{
    // TODO: open the weatherData.csv file for reading
    FILE *file = fopen("weatherData.csv", "r");
    
    // if successfull
    if (file != NULL)
    {
        // TODO: declare an array to store the weather data
        Weather weatherData[DATA_SIZE];

        // TODO: declare a variable to store the weather condition
        int weatherCondition;

        // TODO: read the file and store the data in the array
        int i = 0;
        while (i < DATA_SIZE && fscanf(file, "%f,%f,%d", &weatherData[i].temperature, &weatherData[i].humidity, &weatherCondition) == 3)
        {
            if (weatherCondition >= 0 && weatherCondition < NUM_CONDITIONS)
            {
                weatherData[i].condition = (WeatherCondition)weatherCondition;
            }
            else
            {
                printf("Invalid condition in file. Defaulting to Unknown.\n");
                weatherData[i].condition = NUM_CONDITIONS;
            }
            i++;
        }
        


        // TODO: close the file stream
        fclose(file);

        printf("Weather Data:\n");
        for (int j = 0; j < i; j++)
        {
            // TODO: display the weather data
            printf("%.2fC with %.2f%% humidity and %s\n", weatherData[j].temperature, weatherData[j].humidity, getWeatherText(weatherData[j].condition));
        }
        
    }
    else
    {
        fputs("ERROR: Error opening the file.", stderr);
    }
    // return success
    return 0;
}

// TODO: implement the function here
const char* getWeatherText(WeatherCondition condition)
{
    switch (condition)
    {
        case SUNNY:
            return "Sunny";
        case RAINY:
            return "Rainy";
        case CLOUDY:
            return "Cloudy";
        case SNOWY:
            return "Snowy";
        default:
            return "Unknown";
    }
}