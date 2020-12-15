#include <iostream>
#include "Array.h"
#include "Payment.h"
#include <regex>
#include <fstream>

void build_array(Array<Payment> &payment, std::fstream &file);

void tab(Array<Payment> &array);

int main() {
    auto *base_payment = new Payment();
    auto array = Array<Payment>();
    auto payment = Payment();
    std::fstream file(R"(C:\Users\user.v2.0\CLionProjects\payment\input)");
    build_array(array, file);
    std::cout << "\n";
    array.push_back(Payment());
    array.sort();
    for (int i = 0; i < array.get_length(); ++i) {
        std::cout << array[i] << "\n";
    }
    std::cout << "max sum: " << array.max().getSum() << "\n";
    tab(array);
    return 0;
}

void build_array(Array<Payment> &payments, std::fstream &file) {
    while (true) {
        std::string temperary;
        std::getline(file, temperary);
        if (temperary.empty())
            break;
        Payment one_payment = Payment();
        std::regex pattern(R"(^(\d{0,9}[.,]?\d{0,2}) (\d{20}) ([a-zA-Z .-]+) (\d{20}) ([a-zA-Z .-]+)$)");
        std::smatch results;
        bool correct = std::regex_search(temperary, results, pattern);
        if (!correct) {
            throw std::invalid_argument("incorrect input values");
        }
        int i = 0;
        std::string temp_for_class = "";
        for (; temperary[i] != ' '; ++i) {
            temp_for_class += temperary[i];
        }
        i++;
        one_payment.setSum(std::stof(temp_for_class));
        temp_for_class = "";
        for (; temperary[i] != ' '; i++) {
            temp_for_class += temperary[i];
        }
        i++;
        one_payment.setPayeeAccount(temp_for_class);
        temp_for_class = "";
        for (; !(temperary[i] >= '0' && temperary[i] <= '9'); i++) {
            temp_for_class += temperary[i];
        }
        one_payment.setPayeeOrg(temp_for_class);
        temp_for_class = "";
        for (; temperary[i] != ' '; i++) {
            temp_for_class += temperary[i];
        }
        i++;
        one_payment.setPayerAccount(temp_for_class);
        temp_for_class = "";
        for (; i < temperary.size(); i++) {
            temp_for_class += temperary[i];
        }
        one_payment.setPayerOrg(temp_for_class);
        payments.push_back(one_payment);
    }

}


void tab(Array<Payment> &array) {
    std::vector<std::string> payers;
    std::vector<std::string> payee;
    for (int i = 0; i < array.get_length(); ++i) {
        bool new_payer = true;
        std::string temp = array[i].getPayerOrg();
        for (int j = 0; j < payers.size(); ++j) {
            if (payers[j] == temp) {
                payee[j] += ", " + array[i].getPayeeOrg();
                new_payer = false;
                break;
            }
        }
        if (new_payer) {
            payers.push_back(temp);
            payee.push_back(array[i].getPayeeOrg());
        }
    }
    int first = 18, second = 18;
    for (int i = 0; i < payers.size(); i++) {
        if (payers[i].size() > first) {
            first = payers[i].size();
        }
        if (payee[i].size() > second) {
            second = payee[i].size();
        }
    }
    std::ofstream table;
    try {
        table.open(R"(C:\Users\user.v2.0\CLionProjects\payment\table)");
        std::string upline = "";
        for (int i = 0; i < first + second + 7; ++i) {
            upline += "-";
        }
        table << upline << "\n";
        std::string temp = "| payer organisation";
        for (int j = 0; j < first - 18; ++j) {
            temp += " ";
        }
        temp += "| payee organisation";
        for (int j = 0; j < second - 18 + 2; ++j) {
            temp += " ";
        }
        temp += "|";
        table << temp << "\n";
        for (int i = 0; i < payers.size(); ++i) {
            table << upline << "\n";
            temp = "| " + payers[i];
            for (int j = 0; j < first - payers[i].size(); ++j) {
                temp += " ";
            }
            temp += "| " + payee[i];
            for (int j = 0; j < second - payee[i].size() + 2; ++j) {
                temp += " ";
            }
            temp += "|";
            table << temp << "\n";
        }
        table << upline << "\n";
        table.close();
    }
    catch (...) {
        table.close();
        throw std::invalid_argument("writing file error");
    }
}