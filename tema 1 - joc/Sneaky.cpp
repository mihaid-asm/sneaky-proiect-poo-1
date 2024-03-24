#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<cmath>
using namespace std;

class Monster{
    int health,atk_dmg,atk_rng;
    int coord_x,coord_y;
    char look;
public:
    int getHealth(){return health;}
    int getAttackDamage(){return atk_dmg;}
    int getAttackRange(){return atk_rng;}
    int getCoordX(){return coord_x;}
    int getCoordY(){return coord_y;}
    char getLook(){return look;}
    void setHealth(int h){health=h;}
    void setAttackDamage(int d){atk_dmg=d;}
    void setCoordX(int x){coord_x=x;}
    void setCoordY(int y){coord_y=y;}
    void setLook(char l){look=l;}
    Monster(Monster &MO){health=MO.health; atk_dmg=MO.atk_dmg; atk_rng=MO.atk_rng; coord_x=MO.coord_x; coord_y=MO.coord_y; look=MO.look;}
    Monster(): health(0), atk_dmg(0), atk_rng(0), coord_x(0), coord_y(0), look(' '){}
    Monster(int h,int d,int r,int x,int y, char l){}
    friend ostream & operator<<(ostream &out, const Monster &M);
    friend ifstream & operator>>(ifstream &in, Monster &M);
};
ostream & operator<<(ostream &out, const Monster &M){
    out<<M.look<<": ";
    out<<M.health<<"HP ";
    out<<M.atk_dmg<<"DMG ";
    out<<M.atk_rng<<"RNG ";
    out<<"("<<M.coord_x<<", "<<M.coord_y<<") ";
    return out;
}
ifstream & operator>>(ifstream &in, Monster &M){
    in>>M.health>>M.atk_dmg>>M.atk_rng>>M.coord_x>>M.coord_y>>M.look;
    return in;
}

class Player{
    Monster P1;
    int points;
public:
    Monster& getMonster(){return P1;}
    int getPoints(){return points;}
    void setPoints(int p){points=p;}
    Player(): P1(0,0,0,0,0,' '), points(0){}
    Player(const Monster& mons){
        this->P1 = mons;
        this->points = 0;
    }
    friend ostream & operator<<(ostream &out, const Player &M);
    friend ifstream & operator>>(ifstream &in, Player &P);
};
ostream & operator<<(ostream &out, const Player &M){
    cout<<M.P1;
    cout<<M.points;
    return out;
}
ifstream & operator>>(ifstream &in, Player &P){
    in>>P.P1;
    in>>P.points;
    return in;
}

class Item{
    int points,coord_x,coord_y;
public:
    ~Item(){}
    int getPoints(){return points;}
    int getCoordX(){return coord_x;}
    int getCoordY(){return coord_y;}
    void setPoints(int p){points=p;}
    Item(Item &IT){points=IT.points; coord_x=IT.coord_x; coord_y=IT.coord_y;}
    Item(): points(0), coord_x(0), coord_y(0){}
    friend ostream & operator<<(ostream &out, const Item &I);
    friend ifstream & operator>>(ifstream &in, Item &I);
    Item& operator=(Item &I1){points=I1.points; coord_x=I1.coord_x; coord_y=I1.coord_y; return I1;}
};
ostream & operator<<(ostream &out, const Item &I){
    cout<<I.points<<"PTS at ("<<I.coord_x<<", "<<I.coord_y<<")\n";
    return out;
}
ifstream & operator>>(ifstream &in, Item &I){
    in>>I.points>>I.coord_x>>I.coord_y;
    return in;
}
class Level{
    int height,width;
    Player ONE;
    int no_monsters;
    Monster M[20];
    int no_items;
    Item I[20];
    int target;
    bool over;
public:
    int getHeight(){return height;}
    int getWidth(){return width;}
    int getNumberOfMonsters(){return no_monsters;}
    int getNumberOfItems(){return no_items;}
    int getTarget(){return target;}
    bool getOver(){return over;}
    Player& getPlayer(){return ONE;}
    Monster& getMonster(int index){return M[index];}
    Item& getItem(int index){return I[index];}
    void setNumberOfMonsters(int m){no_monsters=m;}
    void setNumberOfItems(int i){no_items=i;}
    void setOver(bool o){over=o;}
    void setPlayer(Player P){ONE=P;}
    void setMonster(Monster MO, int index){M[index]=MO;}
    void setItem(Item IT, int index){I[index]=IT;}
    Level(): height(0), width(0), ONE(Monster(0, 0, 0, 0, 0, ' ')), no_monsters(0), no_items(0), target(0){}
    friend ostream & operator<<(ostream &out, const Level &L);
    friend ifstream & operator>>(ifstream &in, Level &L);
};
ostream & operator<<(ostream &out, const Level &L){
    cout<<L.height<<" "<<L.width<<endl;
    cout<<L.ONE<<endl;
    cout<<L.no_monsters<<endl;
    for(int i=0;i<L.no_monsters;i++){
        cout<<L.M[i]<<endl;
    }
    cout<<L.no_items<<endl;
    for(int i=0;i<L.no_items;i++){
        cout<<L.I[i]<<endl;
    }
    cout<<L.target;
    return out;
}
ifstream & operator>>(ifstream &in, Level &L){
    in>>L.height>>L.width;
    in>>L.ONE;
    in>>L.no_monsters;
    for(int i=0;i<L.no_monsters;i++){
        in>>L.M[i];
    }
    in>>L.no_items;
    for(int i=0;i<L.no_items;i++){
        in>>L.I[i];
    }
    in>>L.target;
    return in;
}

int main(){
    int choice;
    cout<<"Choose a level between 1 and 3: ";
    cin>>choice;
    char nolevel[2];
    nolevel[0]='0'+choice;
    strcat(nolevel,"joc.in");
    ifstream fin(nolevel);
    Level L1;
    fin>>L1;
    char harta[52][52];
    L1.setOver(false);
        while(!L1.getOver()){
            system("cls");
            if(L1.getTarget()<=L1.getPlayer().getPoints()){
                L1.setOver(true);
                cout<<"YOU WON\n";
            }
            else if(L1.getPlayer().getMonster().getHealth()<=0){
                L1.setOver(true);
                cout<<"YOU LOST\n";
            }
            for(int i=0;i<=L1.getHeight()+1;i++){
                for(int j=0;j<=L1.getWidth()+1;j++){
                    harta[i][j]=' ';
                }
            }
            for(int i=0;i<=L1.getHeight()+1;i++){
                for(int j=0;j<=L1.getWidth()+1;j++){
                    if(i==0 || j==0 || i==L1.getHeight()+1 || j==L1.getWidth()+1) harta[i][j]='#';
                    for(int k=0;k<L1.getNumberOfMonsters();k++){
                        harta[L1.getMonster(k).getCoordX()][L1.getMonster(k).getCoordY()]=L1.getMonster(k).getLook();
                    }
                    for(int k=0;k<L1.getNumberOfItems();k++){
                        if(L1.getItem(k).getPoints()>0)
                            harta[L1.getItem(k).getCoordX()][L1.getItem(k).getCoordY()]='0'+L1.getItem(k).getPoints();
                        else
                            harta[L1.getItem(k).getCoordX()][L1.getItem(k).getCoordY()]=' ';
                    }
                    harta[L1.getPlayer().getMonster().getCoordX()][L1.getPlayer().getMonster().getCoordY()]=L1.getPlayer().getMonster().getLook();
                }
            }
            for(int i=0;i<=L1.getHeight()+1;i++){
                for(int j=0;j<=L1.getWidth()+1;j++){
                    cout<<harta[i][j];
                }
                cout<<endl;
            }
            cout<<L1.getPlayer()<<"/"<<L1.getTarget()<<"PTS"<<endl;
            for(int i=0;i<L1.getNumberOfMonsters();i++){
                cout<<L1.getMonster(i)<<endl;
            }
            if(toupper(getch())=='W' && L1.getPlayer().getMonster().getCoordX()>1){
                int x=L1.getPlayer().getMonster().getCoordX();
                x--;
                L1.getPlayer().getMonster().setCoordX(x);
            }
            if(toupper(getch())=='A' && L1.getPlayer().getMonster().getCoordY()>1){
                int y=L1.getPlayer().getMonster().getCoordY();
                y--;
                L1.getPlayer().getMonster().setCoordY(y);
            }
            if(toupper(getch())=='S' && L1.getPlayer().getMonster().getCoordX()<L1.getHeight()){
                int x=L1.getPlayer().getMonster().getCoordX();
                x++;
                L1.getPlayer().getMonster().setCoordX(x);
            }
            if(toupper(getch())=='D' && L1.getPlayer().getMonster().getCoordY()<L1.getWidth()){
                int y=L1.getPlayer().getMonster().getCoordY();
                y++;
                L1.getPlayer().getMonster().setCoordY(y);
            }
            for(int i=0;i<L1.getNumberOfItems();i++){
                if(L1.getPlayer().getMonster().getCoordX() == L1.getItem(i).getCoordX()){
                    if(L1.getPlayer().getMonster().getCoordY() == L1.getItem(i).getCoordY()){
                        int p=L1.getPlayer().getPoints();
                        p+=L1.getItem(i).getPoints();
                        L1.getPlayer().setPoints(p);
                        int n=L1.getNumberOfItems();
                        n--;
                        L1.setNumberOfItems(n);
                        for(int j=i;j<n;j++){
                            Item aux(L1.getItem(j+1));
                            L1.setItem(aux,j);
                        }
                        L1.getItem(n).setPoints(0);
                    }
                }
            }
            for(int i=0;i<L1.getNumberOfMonsters();i++){
                if(abs(L1.getPlayer().getMonster().getCoordX()-L1.getMonster(i).getCoordX())<=L1.getMonster(i).getAttackRange()){
                    if(abs(L1.getPlayer().getMonster().getCoordY()-L1.getMonster(i).getCoordY())<=L1.getMonster(i).getAttackRange()){
                        int HP=L1.getPlayer().getMonster().getHealth();
                        HP-=L1.getMonster(i).getAttackDamage();
                        L1.getPlayer().getMonster().setHealth(HP);
                    }
                }
            }
            for(int i=0;i<L1.getNumberOfMonsters();i++){
                if(abs(L1.getPlayer().getMonster().getCoordX()-L1.getMonster(i).getCoordX())<=L1.getPlayer().getMonster().getAttackRange()){
                    if(abs(L1.getPlayer().getMonster().getCoordY()-L1.getMonster(i).getCoordY())<=L1.getPlayer().getMonster().getAttackRange()){
                        int HP=L1.getMonster(i).getHealth();
                        HP-=L1.getPlayer().getMonster().getAttackDamage();
                        L1.getMonster(i).setHealth(HP);
                    }
                }
                if(L1.getMonster(i).getHealth()<=0){
                    int n=L1.getNumberOfMonsters();
                    n--;
                    L1.setNumberOfMonsters(n);
                    for(int j=i;j<n;j++){
                        Monster aux(L1.getMonster(j+1));
                        L1.setMonster(aux,j);
                    }
                    L1.getMonster(n).setAttackDamage(0);
                    L1.getMonster(n).setLook(' ');
                }
            }
        }
    fin.close();
    return 0;
}
