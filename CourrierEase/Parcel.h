#pragma once

using namespace System;

namespace CourrierEase
{
    public ref class Parcel
    {
    private:
        int parcelId;
        String^ trackingNo;
        int customerId;
        String^ receiverName;
        String^ receiverPhone;
        String^ receiverAddress;
        String^ receiverCity;
        String^ description;
        double weightKg;
        String^ parcelType;
        double declaredValue;

    public:
        Parcel()
        {
            parcelId = 0;
            trackingNo = "";
            customerId = 0;
            receiverName = "";
            receiverPhone = "";
            receiverAddress = "";
            receiverCity = "";
            description = "";
            weightKg = 0.0;
            parcelType = "";
            declaredValue = 0.0;
        }

        property int ParcelId
        {
            int get()
            {
                return parcelId;
            }

            void set(int value)
            {
                parcelId = value;
            }
        }

        property String^ TrackingNo
        {
            String^ get()
            {
                return trackingNo;
            }

            void set(String^ value)
            {
                trackingNo = value;
            }
        }

        property int CustomerId
        {
            int get()
            {
                return customerId;
            }

            void set(int value)
            {
                customerId = value;
            }
        }

        property String^ ReceiverName
        {
            String^ get()
            {
                return receiverName;
            }

            void set(String^ value)
            {
                receiverName = value;
            }
        }

        property String^ ReceiverPhone
        {
            String^ get()
            {
                return receiverPhone;
            }

            void set(String^ value)
            {
                receiverPhone = value;
            }
        }

        property String^ ReceiverAddress
        {
            String^ get()
            {
                return receiverAddress;
            }

            void set(String^ value)
            {
                receiverAddress = value;
            }
        }

        property String^ ReceiverCity
        {
            String^ get()
            {
                return receiverCity;
            }

            void set(String^ value)
            {
                receiverCity = value;
            }
        }

        property String^ Description
        {
            String^ get()
            {
                return description;
            }

            void set(String^ value)
            {
                description = value;
            }
        }

        property double WeightKg
        {
            double get()
            {
                return weightKg;
            }

            void set(double value)
            {
                weightKg = value;
            }
        }

        property String^ ParcelType
        {
            String^ get()
            {
                return parcelType;
            }

            void set(String^ value)
            {
                parcelType = value;
            }
        }

        property double DeclaredValue
        {
            double get()
            {
                return declaredValue;
            }

            void set(double value)
            {
                declaredValue = value;
            }
        }
    };
}