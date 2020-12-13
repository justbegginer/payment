//
// Created by user.v2.0 on 13.12.2020.
//
#include <string>
#include <ostream>

#ifndef PAYMENT_PAYMENT_H
#define PAYMENT_PAYMENT_H


class Payment {
private:
    float sum;
    std::string payer_account;
    std::string payer_org;
    std::string payee_account;
    std::string payee_org;
public:
    Payment();

    Payment(float sum, const std::string &payerAccount, const std::string &payerOrg, const std::string &payeeAccount,
            const std::string &payeeOrg);

    Payment(const Payment &another_payment);

    float getSum() const;

    void setSum(float sum);

    const std::string &getPayerAccount() const;

    void setPayerAccount(const std::string &payerAccount);

    const std::string &getPayerOrg() const;

    void setPayerOrg(const std::string &payerOrg);

    const std::string &getPayeeAccount() const;

    void setPayeeAccount(const std::string &payeeAccount);

    const std::string &getPayeeOrg() const;

    void setPayeeOrg(const std::string &payeeOrg);

    bool operator==(const Payment &rhs) const;

    bool operator!=(const Payment &rhs) const;

    bool operator<(const Payment &rhs) const;

    bool operator>(const Payment &rhs) const;

    bool operator<=(const Payment &rhs) const;

    bool operator>=(const Payment &rhs) const;

    Payment operator+(int rhs);

    Payment operator-(int rhs);

    friend Payment operator+(Payment payment ,float rhs);

    friend Payment operator-(Payment payment ,float rhs);

    friend std::ostream &operator<<(std::ostream &os, const Payment &payment);

    friend std::istream &operator>>(std::istream &input, Payment &payment);

    ~Payment();


};


#endif //PAYMENT_PAYMENT_H
