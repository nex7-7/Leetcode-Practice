#include <iostream>
#include <vector>
using namespace std;

int maxSkill(int s, int n, int d, vector<vector<int>> arr)
{
    int finalSkill = s;
    vector<vector<int>> sort;
    int maxSkillGain = 0;
    int maxSkillGainIndex = 0;
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j][0] > finalSkill)
                continue;
            else if (arr[j][0] <= finalSkill)
            {
                vector<int> *element = new vector<int>;
                element->push_back(j);
                element->push_back(arr[j][0]);
                element->push_back(arr[j][1]);
                sort.push_back(*element);
            }
        }
        if (!sort.empty())
        {
            for (int k = 0; k < sort.size(); k++)
            {
                if (sort[k][2] > maxSkillGain)
                {
                    maxSkillGain = sort[k][2];
                    maxSkillGainIndex = sort[k][0];
                }
            }
            arr.erase(arr.begin() + maxSkillGainIndex);
            finalSkill += maxSkillGain;
            sort.clear();
        }
    }
    return finalSkill;
}

int main()
{
    vector<vector<int>> arr = {{22, 8}, {13, 6}, {100, 4}, {19, 2}, {33, 5}, {37, 9}};
    cout << maxSkill(25, 6, 3, arr) << endl;
    return 0;
}