#include <bits/stdc++.h>

//projekt 2 temat 2 BFS
//Micha³ Kossakowski 197589 ACiR gr 2 sem 2
//Kacper Komorowski 197963 ACiR gr 2 sem 2

using namespace std;

vector<int> G [100001];	//Lista s¹siedztwa
int odw [100001];	//czy odwiedzono
int odl [100001];	//odleg³oœæ od pocz¹tkowego

void BFS (int v){	//od którego zaczynamy
    queue<int> Q;
    odw [v] = 1;	//punkt od którego zaczynamy odwiedzony
    odl [v] = 0;	//odleg³oœæ jego od pocz¹tku to 0
    Q.push(v);	//dodanie punktu do kolejki

    while (!Q.empty())
	{
        int w = Q.front();
        Q.pop();
        
        for (int i = 0; i < G[w].size(); i++)
		{
            int sasiad = G[w][i];
            
            if (odw[sasiad] == 0) 	//jesli nie jest odwiedzony
			{	
				cout <<"odwiedzony wierzcholek: " << sasiad << endl;
                odw [sasiad] = 1;
                odl [sasiad] = odl[w] + 1;
                Q.push (sasiad);
            }
        }
    }

}

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
	int ile_punktow, ile_polaczen, a, b;
    cin >> ile_punktow >> ile_polaczen;
    
    cout << endl;

    for (int i = 1; i <= ile_polaczen; i++)
	{
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
	
	
    BFS(1);
	
	cout << endl;
	
    for (int i = 1; i <= ile_punktow; i++)
	{
        cout << i << " ";
        cout << odl[i] << endl;
    }


return 0;
}

