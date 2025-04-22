#ifndef AIRFREIGHT_H
#define AIRFREIGHT_H

#include "Shipment.h"
#include <iostream>

class AirFreight : public Shipment {
public:
    AirFreight(const std::string& trackingNumber, double weight)
        : Shipment(trackingNumber, weight) {}

    double estimateDeliveryTime() const override {
        return weight * 0.5; 
    }

    void showDetails() const override {
        std::cout << "Air Freight - Tracking: " << trackingNumber
                  << ", Weight: " << weight << "kg\n";
    }
};

#endif
