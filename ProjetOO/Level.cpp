#include "Level.h"

Level::Level()
    :
      m_grille{nullptr},
      m_main{nullptr},
      m_p1{nullptr},
      m_p2{nullptr}
{
}

void Level::Dessiner(sf::RenderWindow *window)
{
    m_grille->dessiner(window);
    //m_main->dessiner(window);
    //m_p1->dessiner(window);
    //m_p2->dessiner(window);
}

void Level::TraiterActions()
{
    for (Actions* a : m_main->get_actions())
    {
        switch (a->get_etat()) {
        case P1:
            ExecuterP1();
            break;
        case P2:
            ExecuterP2();
            break;
        case Avancer:
        case Tourner_Droite:
        case Tourner_Gauche:
        case Allumer:
            m_grille->TraiterAction(a);
            break;
        default:
            break;
        }
    }
}

void Level::ExecuterP1()
{
    for (Actions* a : m_p1->get_actions())
    {
        switch (a->get_etat()) {
        case P1:
            ExecuterP1();
            break;
        case P2:
            ExecuterP2();
            break;
        case Avancer:
        case Tourner_Droite:
        case Tourner_Gauche:
        case Allumer:
            m_grille->TraiterAction(a);
            break;
        default:
            break;
        }
    }
}

void Level::ExecuterP2()
{
    for (Actions* a : m_p1->get_actions())
    {
        switch (a->get_etat()) {
        case P1:
            ExecuterP1();
            break;
        case P2:
            ExecuterP2();
            break;
        case Avancer:
        case Tourner_Droite:
        case Tourner_Gauche:
        case Allumer:
            m_grille->TraiterAction(a);
            break;
        default:
            break;
        }
    }
}

bool Level::LoadLevel(std::string filename)
{
    std::string path = CHEMIN_NIVEAUX + filename;

    tinyxml2::XMLDocument niveau;
    tinyxml2::XMLError loadERROR = niveau.LoadFile(path.c_str());

    if (!loadERROR)
    {
        tinyxml2::XMLNode * root = niveau.FirstChildElement("Level");

        if (root != nullptr)
        {
            tinyxml2::XMLElement * grille = root->FirstChildElement("Grille");

            if (grille != nullptr)
            {
                m_grille = new Grille();
                tinyxml2::XMLElement * robot  = grille->FirstChildElement("Robot");

                if (robot != nullptr)
                {
                    tinyxml2::XMLElement * position = robot->FirstChildElement("Position");

                    std::stringstream ss  (position->GetText());
                    std::vector<std::string> output;
                    std::vector<int> v;

                    int i;

                    while (ss >> i)
                    {
                        v.push_back(i);

                        if (ss.peek() == ';')
                            ss.ignore();
                    }

                    tinyxml2::XMLElement * direction = robot->LastChildElement("Direction");

                    std::string dir = direction->GetText();

                    sf::Vector2i pos_robot{v[0],v[1]};

                    m_grille->set_robot(pos_robot,std::stoi(dir));
                }

                if (grille->FirstChildElement("Case") != nullptr)
                {
                    for(tinyxml2::XMLElement * elem = grille->FirstChildElement("Case"); elem != nullptr; elem = elem->NextSiblingElement("Case"))
                    {
                        //TODO
                    }
                }



            }
        }
    }

}

