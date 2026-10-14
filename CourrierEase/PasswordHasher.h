#pragma once

using namespace System;
using namespace System::Security::Cryptography;

namespace CourrierEase
{
    public ref class PasswordHasher
    {
    public:
        static String^ HashPassword(String^ password)
        {
            array<Byte>^ salt = gcnew array<Byte>(16);

            RandomNumberGenerator^ rng =
                RandomNumberGenerator::Create();

            rng->GetBytes(salt);

            Rfc2898DeriveBytes^ pbkdf2 =
                gcnew Rfc2898DeriveBytes(
                    password,
                    salt,
                    100000,
                    HashAlgorithmName::SHA256
                );

            array<Byte>^ hash = pbkdf2->GetBytes(32);

            String^ saltText =
                Convert::ToBase64String(salt);

            String^ hashText =
                Convert::ToBase64String(hash);

            return saltText + ":" + hashText;
        }


        static bool VerifyPassword(
            String^ password,
            String^ storedPassword)
        {
            array<String^>^ parts =
                storedPassword->Split(':');

            if (parts->Length != 2)
            {
                return false;
            }

            array<Byte>^ salt =
                Convert::FromBase64String(parts[0]);

            array<Byte>^ storedHash =
                Convert::FromBase64String(parts[1]);

            Rfc2898DeriveBytes^ pbkdf2 =
                gcnew Rfc2898DeriveBytes(
                    password,
                    salt,
                    100000,
                    HashAlgorithmName::SHA256
                );

            array<Byte>^ newHash =
                pbkdf2->GetBytes(32);

            if (newHash->Length != storedHash->Length)
            {
                return false;
            }

            for (int i = 0; i < newHash->Length; i++)
            {
                if (newHash[i] != storedHash[i])
                {
                    return false;
                }
            }

            return true;
        }
    };
}