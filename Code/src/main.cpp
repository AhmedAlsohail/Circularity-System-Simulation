#include "iostream"
#include "Heart.h"
#include "Blood.h"
#include <thread>     // for sleep_for

double liter2ml = 1000.0;

int main(){
    Blood blood = Blood(); // single blood cell
    double timeStep = 0.1;
    double currentTime = 0;

    for (int i = 0; true; i++)
    {
        currentTime = timeStep * i;

        blood.update(timeStep, currentTime);
    
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(100)));
    }

    /*
    Heart heart = Heart( 300.0, 13.0, 780.0, 0);

    double bloodLitres = 5.0; // An adult having an average weight between 65 to 80 kg should have about 4.5 to 5.7 liters of blood,and it make ~6-8% of the body weight.
    int bloodArraySize = 1000;

    
    std::cout << heart.getWeight() << std::endl;
    std::cout << heart.getLength() << std::endl;
    std::cout << heart.getVolume() << std::endl;
    std::cout << heart.getCardiacOutput() << std::endl;
    */    
    return 0;
}

    /*
    Meaning of vessel colors:
        blue = transport oxygen-poor | deoxygenated blood
        red = transport oxygen-rich blood
    */

    /*
    -Vascular system consists of 3 types of vessels:
        - Venous vessels    (Orange):   carry blood back to the heart
        - arterial vessels  (Green):    Carry blood away from the heart
        - capillaries       (Purple):     Carry out blood exchange

    -They are all part of a carefully organized cycle known as "Cardiovascular System".
    -The vessels are divided according to the direction of blood flow in relation to the heart.
    */

    /*
        Circulatory System
            THe two cirulatoryh systems:
                - Pulmonary circulation (small circulation):
                    The circle of heart sending deoxygenated blood to lung and lung sending it back to heart

                - Systemic Circulation (Large Circulation):
                    THe circle of heart sending oxygen-rich blood to the body periphery

                - The heart serve as the center of both criculations.

        Subdivision of the vessels:
            - Arterial vessels carry blood away from heart:
                * Carry oxygen-poor blood to lungs
                * Supply oxygen-rich blood to the body
                
            - Venous Vessels carry blood back to the heart:
                * Carry oxygen-rich blood from the lungs to the heart.
                * Carry oxygen-poor blood from the body to the heart.
    */