#pragma once
#pragma once

using namespace System;

namespace CourrierEase
{
    // Abstract base class
    public ref class DeliveryService abstract
    {
    public:
        virtual double CalculateCharge(double weightKg) = 0;

        virtual String^ GetServiceName() = 0;
    };


    // Standard delivery
    public ref class StandardDelivery : public DeliveryService
    {
    public:
        virtual double CalculateCharge(double weightKg) override
        {
            double baseCharge = 250.0;
            double chargePerKg = 80.0;

            return baseCharge + (weightKg * chargePerKg);
        }

        virtual String^ GetServiceName() override
        {
            return "Standard";
        }
    };


    // Express delivery
    public ref class ExpressDelivery : public DeliveryService
    {
    public:
        virtual double CalculateCharge(double weightKg) override
        {
            double baseCharge = 400.0;
            double chargePerKg = 120.0;

            return baseCharge + (weightKg * chargePerKg);
        }

        virtual String^ GetServiceName() override
        {
            return "Express";
        }
    };
}