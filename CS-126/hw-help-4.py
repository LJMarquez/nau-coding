def days_in_month( month_number ):
    if month_number == 1 or month_number == 3 or month_number == 5 or month_number == 7 or month_number == 8 or month_number == 10 or month_number == 12:
        return 31
    elif month_number == 4 or month_number == 6 or month_number == 9 or month_number == 11:
        return 30
    else:
        return 28