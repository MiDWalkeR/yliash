#include <iostream>
#include <string>
#include <vector>
#include <numeric>

/*Naming convention?*/
using namespace std;

namespace Score
{

//!< Types which can be used for sorting: age and score
enum class SortType
{
    BY_AVG_AGE = 0,
    BY_AVG_SCORE 
};

class Person 
{
private: 
    string m_name;
    string m_surname;
    string m_patronymic;
    uint8_t m_age;
    float m_avg_score;

public:
    Person(
        string name = "",
        string surname = "",
        string patronymic = "",
        uint8_t age = 0,
        float avg_score = 0.0)
    {
        m_age = age;
        m_name = name;
        m_surname = surname;
        m_avg_score = avg_score;
        m_patronymic = patronymic;
    }

    uint8_t getAge()
    {
        return m_age; 
    }

    float getAvgScore()
    {
        return m_avg_score; 
    }

    //!< Sort vector list by corresponding type
    //!< param[in] type Sort type: BY_AVG_SCORE or BY_AVG_AGE
    //!< param[in] personList reference to the list to be sorted
    //
    //!< \return None 
    static void sortBy(SortType type, vector<Person> &personList);
    //!< Returning average age from the person list
    //!< param[in] personList reference to the list to be sorted
    //
    //!< \return average age of persons in a list
    static uint8_t getAvgAge(vector<Person> &personList);
};

uint8_t Person::getAvgAge(vector<Person> &personList)
{
    if(personList.empty())
    {
        printf("List is empty\r\n");
        return 0; 
    }

    size_t sum =
        accumulate(
            personList.begin(),
            personList.end(),
            0, 
            [](size_t prev_result, Person &person)
            {
                return person.getAge() + prev_result; //ask about const qualifier
            });

    return sum / personList.size();
}

void Person::sortBy(SortType type, vector<Person> &personList)
{
    sort(
        personList.begin(),
        personList.end(),
        [type](Person &arg1, Person &arg2)
        {
           return (type == SortType::BY_AVG_AGE)? 
                      (arg1.getAge() < arg2.getAge()) :
                      (arg1.getAvgScore() < arg2.getAvgScore());
        });
}

//!< Print out values depending on sortType
//!< param[in] personList reference to the list to be sorted
//!< param[in] type Sort type: BY_AVG_SCORE or BY_AVG_AGE
//
//!< \return None 
void print(vector<Person> const &personList, SortType type)
{
    if(personList.empty())
    {
        printf("List is empty\r\n");
        return; 
    }

    for(Person i: personList)
    {
        if(type == SortType::BY_AVG_AGE)
        {
            printf("%d\r\n", i.getAge());

        } else
        {
            printf("%.2f\r\n", i.getAvgScore());
        }
    }
}

} //namespace Score

int main()
{
    using namespace Score;

    vector<Person> personList =
    {
        {Person("Vasiliu", "Urgent", "Anatolievich", 18, 5.5)},
        {Person("Dmitriy", "Shtirz", "Karelovich", 40, 9.6)},
        {Person("Ivan", "Jilich", "Asanalievich", 55, 25.1)},
        {Person("Kostya", "Buriu", "Kvazimodovich", 23, 45.3)},
        {Person("Roman", "Belshin", "Tavrievich", 16, 44.6)}
    };

    printf("Sorted by age\r\n");
    Person::sortBy(SortType::BY_AVG_AGE, personList);
    print(personList, SortType::BY_AVG_AGE);

    printf("Sorted by score\r\n");
    Person::sortBy(SortType::BY_AVG_SCORE, personList);
    print(personList, SortType::BY_AVG_SCORE);

    printf("Average age is: %d\r\n", Person::getAvgAge(personList));

    return 0;
}
