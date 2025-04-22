#ifndef SHIPMENT_H
#define SHIPMENT_H

#include <string>

class Shipment {
protected:
    std::string trackingNumber;
    double weight;

public:
    Shipment(const std::string& trackingNumber, double weight)
        : trackingNumber(trackingNumber), weight(weight) {}

    virtual ~Shipment() {}

    virtual double estimateDeliveryTime() const = 0;
    virtual void showDetails() const = 0;
};

#endif
