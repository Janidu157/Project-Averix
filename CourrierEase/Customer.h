#pragma once

using namespace System;

namespace CourrierEase
{
    public ref class Customer
    {
    private:
        int customerId;
        String^ fullName;
        String^ phone;
        String^ email;
        String^ address;

    public:
        Customer()
        {
            customerId = 0;
            fullName = "";
            phone = "";
            email = "";
            address = "";
        }

        Customer(int id, String^ name, String^ phoneNo,
            String^ emailAddress, String^ customerAddress)
        {
            customerId = id;
            fullName = name;
            phone = phoneNo;
            email = emailAddress;
            address = customerAddress;
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

        property String^ FullName
        {
            String^ get()
            {
                return fullName;
            }

            void set(String^ value)
            {
                fullName = value;
            }
        }

        property String^ Phone
        {
            String^ get()
            {
                return phone;
            }

            void set(String^ value)
            {
                phone = value;
            }
        }

        property String^ Email
        {
            String^ get()
            {
                return email;
            }

            void set(String^ value)
            {
                email = value;
            }
        }

        property String^ Address
        {
            String^ get()
            {
                return address;
            }

            void set(String^ value)
            {
                address = value;
            }
        }
    };
}