echo "Enter a year: "
read year

if [ $((year % 400)) -eq 0 ]; then echo "Year $year is a leap year.";
elif [ $((year % 100)) -eq 0 ]; then echo "Year $year is not a leap year.";
elif [ $((year % 4)) -eq 0 ]; then echo "Year $year is a leap year.";
else echo "Year $year is not a leap year.";
fi
