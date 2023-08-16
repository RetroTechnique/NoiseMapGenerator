/**
 *
 * Noise Map Generator
 *
 * MIT License
 *
 * Copyright (c) 2023 Retro Technique
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "NoiseMapGenerator.h"
#include "MainFrm.h"

#include "MainDocument.h"
#include "MainTabView.h"

#ifdef _DEBUG
#define new    DEBUG_NEW
#endif


// CNoiseMapGeneratorApp

BEGIN_MESSAGE_MAP(CNoiseMapGeneratorApp, CWinAppEx)
ON_COMMAND(ID_APP_ABOUT, &CNoiseMapGeneratorApp::OnAppAbout)
// Commandes de document de fichier standard
ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// Construction de CNoiseMapGeneratorApp

CNoiseMapGeneratorApp::CNoiseMapGeneratorApp() noexcept
{
   m_bHiColorIcons = TRUE;


   // TODO: remplacer la chaîne d'ID de l'application ci-dessous par une chaîne ID unique ; le format recommandé
   // pour la chaîne est CompanyName.ProductName.SubProduct.VersionInformation
   SetAppID(_T("NoiseMapGenerator.AppID.NoVersion"));

   // TODO: ajoutez ici du code de construction,
   // Placez toutes les initialisations significatives dans InitInstance
}

// Le seul et unique objet CNoiseMapGeneratorApp

CNoiseMapGeneratorApp theApp;


// Initialisation de CNoiseMapGeneratorApp

BOOL CNoiseMapGeneratorApp::InitInstance()
{
   CWinAppEx::InitInstance();


   EnableTaskbarInteraction(FALSE);

   // AfxInitRichEdit2() est obligatoire pour utiliser un contrôle RichEdit
   // AfxInitRichEdit2();

   // Initialisation standard
   // Si vous n'utilisez pas ces fonctionnalités et que vous souhaitez réduire la taille
   // de votre exécutable final, vous devez supprimer ci-dessous
   // les routines d'initialisation spécifiques dont vous n'avez pas besoin.
   // Changez la clé de Registre sous laquelle nos paramètres sont enregistrés
   // TODO: modifiez cette chaîne avec des informations appropriées,
   // telles que le nom de votre société ou organisation
   SetRegistryKey(_T("Retro Technique"));
   LoadStdProfileSettings(4);    // Charge les options de fichier INI standard (y compris les derniers fichiers utilisés)


   InitContextMenuManager();

   InitKeyboardManager();

   InitTooltipManager();
   CMFCToolTipInfo ttParams;
   ttParams.m_bVislManagerTheme = TRUE;
   theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
                                                RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

   // Inscrire les modèles de document de l'application.  Ces modèles
   //  lient les documents, fenêtres frame et vues entre eux
   CSingleDocTemplate* pDocTemplate;
   pDocTemplate = new CSingleDocTemplate(
      IDR_MAINFRAME,
      RUNTIME_CLASS(CMainDocument),
      RUNTIME_CLASS(CMainFrame),           // fenêtre frame SDI principale
      RUNTIME_CLASS(CMainTabView));
   if (!pDocTemplate)
   {
      return FALSE;
   }
   AddDocTemplate(pDocTemplate);


   // Analyser la ligne de commande pour les commandes shell standard, DDE, ouverture de fichiers
   CCommandLineInfo cmdInfo;
   ParseCommandLine(cmdInfo);

   // Activer les ouvertures d'exécution DDE
   EnableShellOpen();
   RegisterShellFileTypes(TRUE);


   // Commandes de dispatch spécifiées sur la ligne de commande.  Retournent FALSE si
   // l'application a été lancée avec /RegServer, /Register, /Unregserver ou /Unregister.
   if (!ProcessShellCommand(cmdInfo))
   {
      return FALSE;
   }

   // La seule fenêtre a été initialisée et peut donc être affichée et mise à jour
   m_pMainWnd->ShowWindow(SW_SHOW);
   m_pMainWnd->UpdateWindow();
   // appelle DragAcceptFiles uniquement s'il y a un suffixe
   //  Dans une application SDI, cet appel doit avoir lieu juste après ProcessShellCommand
   // Activer les ouvertures via glisser-déplacer
   m_pMainWnd->DragAcceptFiles();
   return TRUE;
}

// gestionnaires de messages de CNoiseMapGeneratorApp


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:

   CAboutDlg() noexcept;

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
   enum
   {
      IDD = IDD_ABOUTBOX
   };
#endif

protected:

   virtual void DoDataExchange(CDataExchange* pDX);  // Prise en charge de DDX/DDV

// Implémentation

protected:

   DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept
   : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
   CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Commande App pour exécuter la boîte de dialogue
void CNoiseMapGeneratorApp::OnAppAbout()
{
   CAboutDlg aboutDlg;

   aboutDlg.DoModal();
}

// méthodes de chargement/d'enregistrement de la personnalisation de CNoiseMapGeneratorApp

void CNoiseMapGeneratorApp::PreLoadState()
{
   BOOL    bNameValid;
   CString strName;

   bNameValid = strName.LoadString(IDS_EDIT_MENU);
   ASSERT(bNameValid);
   GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CNoiseMapGeneratorApp::LoadCustomState()
{
}

void CNoiseMapGeneratorApp::SaveCustomState()
{
}

// gestionnaires de messages de CNoiseMapGeneratorApp
