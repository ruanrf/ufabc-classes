using UnityEngine;
using UnityEngine.SceneManagement;

public class ManageButtons : MonoBehaviour
{


    // Start is called before the first frame update
    void Start()
    {
        PlayerPrefs.SetInt("score", 0);     // define o score em 0
    }

    // Update is called once per frame

    public void StartGameWorld()            // chama a cena de jogo (Lab1)
    {
        SceneManager.LoadScene("Lab1");
    }

    public void MostrarCreditos()           // chama a cena de creditos (Lab1_Creditos)
    {
        SceneManager.LoadScene("Lab1_Creditos");
    }

    public void VoltarAoMenu()              // chama a cena de menu (Lab1_Menu)
    {
        SceneManager.LoadScene("Lab1_Start");
    }
}
