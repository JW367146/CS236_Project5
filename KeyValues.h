

#ifndef CS236_PROJECT1_KEYVALUES_H
#define CS236_PROJECT1_KEYVALUES_H

template<class Key>

class KeyValues
{
private:


Key key;
std::vector<int> values;

public:
    KeyValues(std::string key){
        this->key = key;
    }
    KeyValues(int key){
        this->key = key;
    }

    void addValue(int value){
        if (!count(values.begin(), values.end(), value))
        {
            values.push_back(value);
        }
    }
    Key getKey() {
        return key;
    }

    std::vector<int> getValues(){
        return values;
    }

    std::string toString() const
    {
        std::stringstream out;

        out << key ;
        for (unsigned int i = 0; i< values.size();i++){
            out << " " << values[i];
        }
        out <<"\n";
        return out.str();
    }

    friend std::ostream& operator<< (std::ostream& os,  KeyValues& myclass)
    {
        os << myclass.toString();
        return os;
    }

};


#endif //CS236_PROJECT1_KEYVALUES_H
