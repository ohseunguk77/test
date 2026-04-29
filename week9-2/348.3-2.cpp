void eat(bool bItemEaten) {
    if (bItemEaten) {
        nEnergy += 8; // 아이템을 먹으면 8 증가
    } else {
        nEnergy -= 1; // 먹지 못하면 1 감소
        if (nEnergy < 0) nEnergy = 0; // 최솟값은 0
    }
}