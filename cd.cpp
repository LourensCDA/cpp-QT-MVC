#include "cd.h"

cd::cd(){}

cd::cd(QString comp, QString alb, double cst, int rate): composer(comp), album(alb), cost(cst), rating(rate) {}

void cd::setComposer(QString comp)
{
    composer = comp;
};

void cd::setAlbum(QString alb)
{
    album = alb;
};

void cd::setCost(double cst)
{
    cost = cst;
};

void cd::setRating(int rate)
{
    rating = rate;
};

QString cd::getComposer() const
{
    return composer;
};

QString cd::getAlbum() const
{
    return album;
};

double cd::getCost() const
{
    return cost;
};

int cd::getRating() const
{
    return rating;
};
