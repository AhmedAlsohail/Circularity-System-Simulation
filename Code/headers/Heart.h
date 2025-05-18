class Heart{
public:
    Heart(double _weight, double _length, double _volume, int _state){
        weight = _weight;
        length = _length;
        volume = _volume;

        if(_state == 0) // At rest
            cardiacOutput = 5.0;
        else // At Physical Extertion
            cardiacOutput = 25.0;
    }

    double getWeight(){
        return weight;
    }

    double getLength(){
        return length;
    }

    double getVolume(){
        return volume;
    }

    double getCardiacOutput(){
        return cardiacOutput;
    }

private:
    double weight; // g
    double length; // cm
    double volume; // ml on average, it can reach up to ~1400ml for competitive athletes
    double cardiacOutput; // liters/minute , Average ~5 at rest and ~25 at Physical Extertion
    
};