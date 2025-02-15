#pragma once   

#include "orderType.h"
#include "side.h"
#include "commonIncludes.h"
#include <chrono>
#include <ctime>


class Order {
    public:
        Order(e_orderType orderType, uint64_t orderId, e_side side, double price, uint64_t initialQuantity) : c_orderType(orderType), c_orderId(orderId), c_side(side), c_price(price), c_initialQuantity(initialQuantity), c_remainingQuantity(initialQuantity) {}
        e_orderType orderType() const { return c_orderType; }
        Order(){}
        uint64_t orderId() const { return c_orderId; }
        e_side side() const { return c_side; }
        double price() const { return c_price; }
	void setPrice(double price) { c_price = price; }
        uint64_t initialQuantity() const { return c_initialQuantity; }
        uint64_t remainingQuantity() const { return c_remainingQuantity; }
        void setRemainingQuantity(uint64_t remainingQuantity) { c_remainingQuantity = remainingQuantity; }
        void Fill(uint64_t quantity) {
            if (quantity > c_remainingQuantity) {
                std::cout << "Error: Trying to fill more than remaining quantity" << std::endl;
                return;
            }
            c_remainingQuantity -= quantity; 
        }
        void setSide(e_side side){c_side = side;}
        void setOrderType(e_orderType orderType){c_orderType = orderType;}
//    private:
        e_orderType c_orderType;
        uint64_t c_orderId;
        e_side c_side;
        double c_price;
        uint64_t c_initialQuantity;
        uint64_t c_remainingQuantity;
//        std::chrono::system_clock::time_point c_timestamp;
};

