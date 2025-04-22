#ifndef GROUNDSHIPMENT_H
#define GROUNDSHIPMENT_H

#include "Shipment.h"
#include <iostream>

class GroundShipment : public Shipment {
public:
    GroundShipment(const std::string& trackingNumber, double weight)
        : Shipment(trackingNumber, weight) {}

    double estimateDeliveryTime() const override {
        return weight * 1.0;  
    }

    void showDetails() const override {
        std::cout << "Ground Shipment - Tracking: " << trackingNumber
                  << ", Weight: " << weight << "kg\n";
    }
};

#endif
