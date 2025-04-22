#include <iostream>
#include <vector>
#include "airfrieght.h"
#include "groundShipment.h"

int main() {
    std::vector<Shipment*> shipments;

    shipments.push_back(new AirFreight("AIR123", 10.5));
    shipments.push_back(new GroundShipment("GRD456", 15.2));

    for (const auto& shipment : shipments) {
        shipment->showDetails();
        std::cout << "Estimated Delivery Time: " 
                  << shipment->estimateDeliveryTime() << " hrs\n\n";
    }

   
    for (auto shipment : shipments) {
        delete shipment;
    }

    return 0;
}
