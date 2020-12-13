//
// Created by user.v2.0 on 13.12.2020.
//
#include <string>

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

    ~Payment();
};


#endif //PAYMENT_PAYMENT_H
