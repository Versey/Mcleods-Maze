#ifndef SCORE_HPP_INCLUDED
#define SCORE_HPP_INCLUDED

class score
{
public:
    score();
    int getAiScore();
    int getPScore();
    void resetAiScore();
    void resetPScore();
    void incAiScore();
    void incPScore();
private:
    int aiScore=0;
    int pScore=0;
};

#endif // SCORE_HPP_INCLUDED
