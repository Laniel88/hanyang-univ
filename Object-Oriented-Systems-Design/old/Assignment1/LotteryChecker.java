public class LotteryChecker {
    public int checkRank(int[] winningNumbers, int[] trialNumbers) {
        int regularMatchCount = 0;
        boolean bonusMatched = false;
        
        for(int i=0; i <winningNumbers.length-1; i++) {
            for(int trialNumber: trialNumbers) {
                if(winningNumbers[i] == trialNumber) {
                    regularMatchCount++;
                    break;
                }
            }
        }
        for(int trialNumber: trialNumbers) {
            if(winningNumbers[6] == trialNumber) {
                bonusMatched = true;
                break;
            }
        }

        if(regularMatchCount == 6 || ( regularMatchCount == 5 ) && bonusMatched)
            return 1;
        else if(regularMatchCount == 5 || ( regularMatchCount == 4 ) && bonusMatched)
            return 2;
        else if(regularMatchCount == 4)
            return 3;
        else if(regularMatchCount == 3)
            return 4;
        else
            return 0;

    }
}
