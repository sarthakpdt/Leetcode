int earliestFinishTime(int* landStartTime, int landStartTimeSize, int* landDuration, int landDurationSize, int* waterStartTime, int waterStartTimeSize, int* waterDuration, int waterDurationSize) {
    int minOverallFinish = 2000000000;

    for (int i = 0; i < landStartTimeSize; i++) {
        for (int j = 0; j < waterStartTimeSize; j++) {
            
            int finishLand = landStartTime[i] + landDuration[i];
            int startWater = (finishLand > waterStartTime[j]) ? finishLand : waterStartTime[j];
            int option1Finish = startWater + waterDuration[j];

            int finishWater = waterStartTime[j] + waterDuration[j];
            int startLand = (finishWater > landStartTime[i]) ? finishWater : landStartTime[i];
            int option2Finish = startLand + landDuration[i];

            if (option1Finish < minOverallFinish) {
                minOverallFinish = option1Finish;
            }
            if (option2Finish < minOverallFinish) {
                minOverallFinish = option2Finish;
            }
        }
    }
    return minOverallFinish;
}