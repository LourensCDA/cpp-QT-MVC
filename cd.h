#ifndef CD_H
#define CD_H

#include <QString>

class cd
{
public:
    cd();
    cd(QString comp, QString alb, double cst, int rate);

    void setComposer(QString comp);
    void setAlbum(QString alb);
    void setCost(double cst);
    void setRating(int rate);

    QString getComposer() const;
    QString getAlbum() const;
    double getCost() const;
    int getRating() const;

private:
    QString composer;
    QString album;
    double cost;
    int rating;
};

#endif // CD_H
