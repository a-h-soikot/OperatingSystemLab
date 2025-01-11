echo "Enter marks: "
read marks

if [ $marks -ge 80 ]; then echo "Grade A+";
elif [ $marks -ge 70 ]; then echo "Grade A";
elif [ $marks -ge 60 ]; then echo "Grade B+";
elif [ $marks -ge 50 ]; then echo "Grade B";
elif [ $marks -ge 40 ]; then echo "Grade C";
else echo "Grade F";
fi
