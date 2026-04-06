#include "fileUtility.h"

bool splitEvenOdd(int *numbers, int size)
{
    FILE *evenFile = fopen(EVEN_FILENAME, "w");
    FILE *oddFile = fopen(ODD_FILENAME, "w");

    if(evenFile != NULL && oddFile != NULL)
    {
        for(int i = 0; i < size; i++)
        {
            if(numbers[i] % 2 == 0)
            {
                fprintf(evenFile, "%d\n", numbers[i]);
            }
            else
            {
                fprintf(oddFile, "%d\n", numbers[i]);
            }
        }
        fclose(evenFile);
        fclose(oddFile);
        return true;
    }
    else
    {
        if(evenFile != NULL)
        {
            fclose(evenFile);
        }
        if(oddFile != NULL)
        {
            fclose(oddFile);
        }
        return false;
    }
}

int readProduct(const char *filename, char productNames[MAX_ARRAY_SIZE][MAX_STRING_SIZE], float productPrices[MAX_ARRAY_SIZE], ProductCategory productCategories[MAX_ARRAY_SIZE])
{
    FILE *file = fopen(filename, "r");
    int count = 0;

    if(file != NULL)
    {
        char name[MAX_STRING_SIZE];
        float price;
        int category;
        char line[MAX_LINE_LENGTH];

        fgets(line, sizeof(line), file);

        while(fscanf(file, "%49[^\t]\t%f\t%d\n", name, &price, &category) == 3 && count < MAX_ARRAY_SIZE)
        {
            if(category < 0 || category >= LEN_CATEGORY)
            {
                category = OTHER;
            }

            strcpy(productNames[count], name);
            productPrices[count] = price;
            productCategories[count] = (ProductCategory)category;
            count++;
        }
        fclose(file);
    }
    return count;
}

bool getAvgRatingPerYear(const char *inputFilename, const char *outputFilename)
{
    FILE *inputFile = fopen(inputFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    if(inputFile != NULL && outputFile != NULL)
    {
        int range = MAX_YEAR - MIN_YEAR + 1;
        float totalRatings[range];
        int movieCounts[range];

        for(int i = 0; i < range; i++)
        {
            totalRatings[i] = 0.0;
            movieCounts[i] = 0;
        }

        char line[MAX_LINE_LENGTH];

        fgets(line, sizeof(line), inputFile);

        while(fgets(line, sizeof(line), inputFile) != NULL)
        {
            char lineCopy[MAX_LINE_LENGTH];
            strcpy(lineCopy, line);

            char *token = strtok(lineCopy, ",");

            int tokenIndex = 0;
            int year = 0;
            float rating = 0.0;

            while(token != NULL)
            {
                if(tokenIndex == 3) 
                {
                    year = atoi(token);
                }
                else if(tokenIndex == 5) 
                {
                    rating = atof(token);
                }

                token = strtok(NULL, ",");
                tokenIndex++;
            }

            int index = year - MIN_YEAR;

            if(index >= 0 && index < range)
            {
                totalRatings[index] += rating;
                movieCounts[index]++;
            }
        }

        fprintf(outputFile, "Year,Ratings\n");
        for(int i = 0; i < range; i++)
        {
            if(movieCounts[i] > 0)
            {
                float avgRating = totalRatings[i] / (float)movieCounts[i];
                int year = i + MIN_YEAR;
                fprintf(outputFile, "%d,%.2f\n", year, avgRating);
            }
        }

        fclose(inputFile);
        fclose(outputFile);
        return true;
    }
    else
    {
        if(inputFile != NULL)
        {
            fclose(inputFile);
        }
        if(outputFile != NULL)
        {
            fclose(outputFile);
        }
        return false;
    }
}