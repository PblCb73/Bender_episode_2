#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

//Класс узла
class Node
{
public:
    Node():_value(0),_tempValue(0),_hasParent(false){}
	//Инициализация узла
    void initValue( int value ){ _value = value; }
	//Установка текущего значения в узле
    void setCurrentValue( int value, bool hasParent )
    {
        _hasParent = hasParent;
		/* Если узел не имеет предка, то мы в этот узел не попадем, 
		   а следовательно, что бы исключит путь из поиска максимального значения 
		   _tempValue будет равно 0 */
        if( _hasParent && value > _tempValue ) _tempValue = value;
    }
	//Получение текущего значения в узле
    int getCurrentValue(){ return _tempValue + _value; }
	//Получения флага того, что узел имеет предка
    bool hasParent(){ return _hasParent; }
        
private:
    int _value;
    int _tempValue;
    bool _hasParent;
};

//Функция для разбиения входной строки на подстроки
vector<string> split(string str)
{
    std::istringstream iss(str);
    vector<string> result( (istream_iterator<string>(iss)), istream_iterator<string>() );
    return result;
}

int main()
{
    int N;
    cin >> N; cin.ignore();
	//Тут хранятся все узлы
    vector<Node> nodes(N);
    //Будем плюсовать текущее значение в узле к значению следующих дочерних узлов,
	//на выходах получим максимальное значение
    for( int i( 0 ); i < N; ++i ){
        string item;
        getline( cin, item );
        vector<string> params( split( item ) );
        nodes[ i ].initValue( stoi( params[ 1 ] ) );
        if( params[ 2 ] != "E" ) nodes[ stoi( params[ 2 ] ) ].setCurrentValue( nodes[ i ].getCurrentValue(), nodes[ i ].hasParent() || i==0 ); 
        if( params[ 3 ] != "E" ) nodes[ stoi( params[ 3 ] ) ].setCurrentValue( nodes[ i ].getCurrentValue(), nodes[ i ].hasParent() || i==0 );
    }
	//найдем максимальное значение, оно и будет решением
    vector<Node>::iterator itNode = max_element( nodes.begin(), nodes.end(), []( Node &lN, Node &rN ){ 
        return lN.getCurrentValue() < rN.getCurrentValue();
    } );
    cout<<(*itNode).getCurrentValue()<<endl;
}