#include "score.hpp"

score::score() {};
int score::getAiScore(){ return aiScore;}
int score::getPScore(){ return pScore;}
void score::resetAiScore(){ aiScore = 0;}
void score::resetPScore(){ pScore = 0;}
void score::incAiScore(){ aiScore++;}
void score::incPScore(){ pScore++;}
