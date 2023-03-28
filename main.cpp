#include <iostream>
#include <string>

enum monthCode {
        jan=1, fev=4, mar=4,
        abr=0, mai=2, jun=5,
        jul=0, ago=3, set=6,
        out=1, nov=4, dez=6
};

bool isLeapYear(int year)
{
    if(year % 4 == 0){
        if(year % 100 == 0){
            if(year % 400 == 0){
                return true;
            } else {
                return false;
            }
        } 
        return true;
    }
    return false;
}

monthCode getMonthCode(int month)
{
    monthCode monthIndexes[] = {
        jan, fev, mar, abr, mai, jun,
        jul, ago, set, out, nov, dez
    };
    return monthIndexes[month-1];
}

int centurySum(int year)
{
    if(year > 2000){
        return 6;
    } else if(year > 1700 && year <= 1800){
        return 4;
    } else if(year > 1800 && year <= 1900){
        return 2;
    } return 0;
}

std::string getWeekDay(int indexDay)
{
    std::string weekDays[] = {
        "Sábado", 
        "Domingo", 
        "Segunda-feira", 
        "Terça-feira", 
        "Quarta-feira",
        "Quinta-feira", 
        "Sexta-feira"
    };
    return weekDays[indexDay];
}

std::string weekDayCalculator(int day, int month, int year)
{

    int lastTwoDigits = year % 100;
    int dividedByFour = lastTwoDigits / 4;
    int dividedPlusDay = dividedByFour + day;

    monthCode monthIndexes = getMonthCode(month);
    int plusMesDay = dividedPlusDay + monthIndexes;

    if(isLeapYear(year)){
        if(month == 1 || month == 2){
            plusMesDay -= 1; 
        }
    }

    int answerPlusCentury = plusMesDay + centurySum(year);
    answerPlusCentury += lastTwoDigits;
    day = answerPlusCentury % 7;
    return getWeekDay(day);
}


int main(int argc, char* argv[])
{
    int day;
    std::cout << "Informe o dia: ";
    std::cin >> day;

    int month;
    std::cout << "Informe o mês: ";
    std::cin >> month;

    int year;
    std::cout << "Informe um ano entre 1700 e 2099: ";
    std::cin >> year;
    while(year < 1700 || year > 2099){
        std::cout << "Por favor, informe um ano entre 1700 e 2099: ";   
        std::cin >> year;
    }
    
    std::string resposta = weekDayCalculator(day, month, year);

    std::cout << resposta << std::endl;

    return 0;
}