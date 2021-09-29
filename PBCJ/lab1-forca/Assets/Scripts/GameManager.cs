using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    private int numTentativas;              // numero de tentativas realizadas
    private int maxNumTentativas;           // numero máximo de tentativas realizadas - Vida ou Forca
    private int score;                      // placar do usuario

    public GameObject letra;                // prefab da letra no Game
    public GameObject centro;               // objeto de texto para indicar o centro da tela

    private string palavraOculta;           // armazena a palavra oculta escolhida
    private int tamPalavraOculta;           // tamanho da palavra oculta
    private int dificuldade = 3;            // adicional de tentativas (numero de tentativas = tamanhoPalavraOculta + dificuldade)

    char[] letrasOcultas;                   // letras da palavra oculta
    bool[] letrasDescobertas;               // indicador de letras descobertas da palavra oculta


    // Start is called before the first frame update
    void Start()
    {
        centro = GameObject.Find("centroDaTela");
        InitGame();
        InitLetras();
        numTentativas = 0;
        score = 0;
        UpdateNumTentativas();
        UpdateScore();
    }

    // Update is called once per frame
    void Update()
    {
        CheckTeclado();                // a cada atualizacao, chama a funcao CheckTeclado
    }

    void InitLetras()
    {
        int numLetras = tamPalavraOculta;
        for (int i = 0; i < numLetras; i++)
        {
            Vector3 novaPosicao;
            novaPosicao = new Vector3(centro.transform.position.x + ((i - numLetras / 2.0f) * 80), centro.transform.position.y, centro.transform.position.z);
            GameObject l = Instantiate(letra, novaPosicao, Quaternion.identity);
            l.name = "letra" + (i + 1);                                       // nomeia na hierarquia a GameObject como letra(i+1)
            l.transform.SetParent(GameObject.Find("Canvas").transform);       // posiciona como filho do GameObject Canvas
        }
    }

     void InitGame()
    {
        palavraOculta = EscolherPalavraDoArquivo();                 // escolhe uma palavra oculta de dentro do arquivo de palavras

        tamPalavraOculta = palavraOculta.Length;                    // determina o comprimento da palavra oculta
        palavraOculta = palavraOculta.ToUpper();                    // coloca a palavraOculta em maiúsculo

        letrasOcultas = new char[(tamPalavraOculta)];               // instancia o array char da palavra oculta
        letrasOcultas = palavraOculta.ToCharArray();                // copia a palavra oculta no array de letras

        letrasDescobertas = new bool[(tamPalavraOculta)];           // instancia o array bool do indicador de acertos
        maxNumTentativas = tamPalavraOculta + dificuldade;          // numero maximo de tentativas
    }

    void CheckTeclado()
    {
        if (Input.anyKeyDown)               // se alguma tecla for pressionada...
        {
            char letraInput = Input.inputString.ToCharArray()[0];           // copia a letra na variavel letraInput
            int letraInputAsInt = System.Convert.ToInt32(letraInput);       // transforma letraInput em int (usado abaixo nas condicoes)

            if (letraInputAsInt >= 97 && letraInputAsInt <= 122)            // se for uma letra (minuscula entre a ~ z)
            {
                numTentativas++;                    // adiciona 1 às tentativas
                UpdateNumTentativas();              // atualiza na tela
                
                if (numTentativas >= maxNumTentativas)      // se exceder as tentativas (derrota)
                {
                    SceneManager.LoadScene("Lab1_Forca");   // troca a cena para a de forca (derrota)
                }

                for (int i = 0; i < tamPalavraOculta; i++)      // varre o array da palavra oculta buscando se a letra já foi descoberta
                {
                    if (!letrasDescobertas[i])
                    {
                        letraInput = char.ToUpper(letraInput);
                        if (letrasOcultas[i] == letraInput)         // se acertou a letra, ...
                        {
                            letrasDescobertas[i] = true;            // posição do array letrasDescobertas como true (encontrada)
                            GameObject.Find("letra" + (i + 1)).GetComponent<Text>().text = letraInput.ToString();   // revela a letra no objeto
                            score = PlayerPrefs.GetInt("score");
                            score++;                                // aumenta o score em 1 por acerto
                            PlayerPrefs.SetInt("score", score);     
                            UpdateScore();                          // atualiza o objeto score
                            VerificaPalavraDescoberta();            // verifica se a palavra foi totalmente descoberta
                        }
                    }
                }
            }
        }
    }

    void UpdateNumTentativas()              // metodo para atualizar o GameObject de numero de tentativas
    {
        GameObject.Find("numTentativas").GetComponent<Text>().text = numTentativas + " | " + maxNumTentativas;
    }

    void UpdateScore()                      // metodo para atualizar o GameObject de score
    {
        GameObject.Find("scoreUI").GetComponent<Text>().text = "Score: " + score;
    }

    void VerificaPalavraDescoberta()        // metodo para verificar se a palavra foi toda descoberta
    {
        bool condicao = true;

        for (int i = 0; i < tamPalavraOculta; i++)
        {
            condicao = condicao && letrasDescobertas[i];    // caso haja uma letra não descoberta, retornara false para 'condicao'
        }
        if (condicao)                       // se a 'condicao' for true (ganhou), ...
        { 
            PlayerPrefs.SetString("ultimaPalavraOculta", palavraOculta);    // insere a palavra oculta no elemento 'ultimaPalavraOculta'
            SceneManager.LoadScene("Lab1_Salvo");                           // troca a cena para a Lab1_Salvo (vitoria)
        }
    }

    string EscolherPalavraDoArquivo()        // metodo para escolher uma palavra entre as presentes no arquivo 'Palavras.txt'
    {
        TextAsset t1 = (TextAsset)Resources.Load("Palavras", typeof(TextAsset));    // leitura do arquivo
        string s = t1.text;
        string[] palavras = s.Split(' ');                                           // separador para as palavras (espaco vazio nesse caso)
        int numPalavraAleatoria = Random.Range(0, palavras.Length + 1);             // escolha de uma palavra dentro do array 'palavras[]'
        return (palavras[numPalavraAleatoria]);                                     // retorna a palavra
    }
}
