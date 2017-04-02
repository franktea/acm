from builtins import property

class Team:
    def __init__(self, name):
        self.name = name
        self.played = 0
        self.wins = 0
        self.ties = 0
        self.losses = 0
        self.scored = 0
        self.against = 0
        
    def AddGame(self, scored, score_against):
        self.played += 1
        self.scored += scored
        self.against += score_against
        
        if scored > score_against:
            self.wins += 1
        elif scored == score_against:
            self.ties += 1
        else:
            self.losses += 1
            
    @property
    def points(self):
        return 3*self.wins + self.ties
    
    @property
    def goal_difference(self):
        return self.scored - self.against
    
    def __str__(self):
        return '{} {}p, {}g ({}-{}-{}), {}gd ({}-{})'.format(self.name, self.points, 
                self.played, self.wins, self.ties, self.losses, self.goal_difference,
                self.scored, self.against)
    
    def __gt__(self, other):
        """按照从大到小排列"""
        if self.points > other.points:
            return True
        elif self.points == other.points:
            if self.wins > other.wins:
                return True
            elif self.wins == other.wins:
                if self.goal_difference > other.goal_difference:
                    return True
                elif self.goal_difference == other.goal_difference:
                    if self.scored > other.scored:
                        return True
                    elif self.scored == other.scored:
                        if self.played < other.played:
                            return True
                        elif self.played == other.played:
                            return self.name.lower() < other.name.lower()
        
        return False
                    
class Tournament:
    def __init__(self, name):
        self.__name = name
        self.__teams = {}
        
    def AddTeam(self, team_name):
        self.__teams[team_name] = Team(team_name)
        
    def AddGameFromeLine(self, line):
        """add game from line of string, like: Brazil#2@1#Scotland """
        teams = [x.split('#') for x in line.split('@')]
        #print('-------->', teams)
        team1, score1 = self.__teams[teams[0][0]], int(teams[0][1])
        team2, score2 = self.__teams[teams[1][1]], int(teams[1][0])

        team1.AddGame(score1, score2)
        team2.AddGame(score2, score1)
    
    def OutPut(self):
        print(self.__name)
        teams = sorted([t for t in self.__teams.values()], reverse=True)
        for index, team in enumerate(teams):
            print('%d)' % (index + 1), team)
            

if __name__ == '__main__':
    case_count = int(input())
    for case_index in range(case_count):
        if case_index > 0:
            print()
            
        game_name = input()
        tour = Tournament(game_name)
        team_count = int(input())
        for _ in range(team_count):
            tour.AddTeam(input())
        game_count = int(input())
        for _ in range(game_count):
            tour.AddGameFromeLine(input())
        
        tour.OutPut()