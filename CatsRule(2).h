#include <list>
#include <string>
#include <utility>
#include <algorithm>


/**
    Class provides 2 public methods: checkIn to put an animal on a waiting queue
                                     seePet - method which returns name of animal next for a vet

    According to rules - Cats have higher priority. All animals are served in order of checking in

    There are 2 lists (queues) for animals: for Cats and for other type of animals.


    checkIn method: first, we make a copy of animal type and convert it to lowercase.
    Next we check if it's a cat (it any writing: Cat, caT, CAT, etc)
    If we match, that it's a cat, specie and animal name is appended to catsQueue
    otherwise, appended to otherQueue member

    seetPet method: according to rule, we first check if there's any waiting Cat (in cat's queue)
        if there's an animal,
            we store name of this animal
            (first in a queue (returned by front() method), and take only name, stored as second field of a std::pair)
            and remove records from front of the queue (pop_front() )
        if there are no cats, we check if there's a pet in otherQueue.
            if there's an animal, we make similar actions as for catQueue (but using otherQueue)

        if non of condition are met, empty string initialized in the beginning of method is returned

*/

class CatsRule
{
    std::list< std::pair<std::string, std::string> > catsQueue;
    std::list< std::pair<std::string, std::string> > otherQueue;

  public:
    void checkIn(const std::string &specie, const std::string &name)
    {
        std::string spec_copy(specie);
        std::transform(spec_copy.begin(), spec_copy.end(),
            spec_copy.begin(), ::tolower);
        if (spec_copy == "cat")
        {
            catsQueue.push_back( { specie,name } );
        } else {
            otherQueue.push_back( { specie,name } );
        }
    }
    std::string seePet() {
        std::string rv("");
        if (catsQueue.empty())
        {
            if (!otherQueue.empty())
            {
                rv = otherQueue.front().second;
                otherQueue.pop_front();
            }
        } else {
            rv = catsQueue.front().second;
            catsQueue.pop_front();
        }
        return rv;
    }
};

