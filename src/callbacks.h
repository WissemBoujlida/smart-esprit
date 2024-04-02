#include <gtk/gtk.h>

void
on_rbfemme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rbhomme_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_afficheraj_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_rechercher_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_enregistrer_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifieraf_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimeraf_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_entrynommo_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data);


void
on_niveau_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retourniveau_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_entrycinaj_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_rbhommemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rbfemmemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_fobuttonaficher_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fobuttonchercher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_fobuttonmeilleur_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fotreeview1_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_fobuttondelete_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fobuttonmodifier1_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_fobuttonretour_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_fobuttonajout1_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_fobuttonajoutermenu_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_foradiop_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_foradior_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_foradiod_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

gboolean
on_fowindowmodifier_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_fobuttonenregistrer_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_focheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_fobuttoncherche2_clicked            (GtkWidget        *button,
                                        gpointer         user_data);

gboolean
on_fowindowsupp_focus_in_event         (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_fobuttonsupp_clicked                (GtkWidget       *button,
                                        gpointer         user_data);
void
on_cabuttonlogin_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_acbgdcrech_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonajouter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonmodifier_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonsupprimer_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttongdcretour_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_caatreeviewgdc_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewtrax_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_cabuttonsretour_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttongdc_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_cabuttons__curit___clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_cabuttonquitter_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

gboolean
on_cawindowmodifier_focus_in_event     (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_caentrymdone_changed                (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_caradiobuttonmdechet_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_caradiobuttondebit_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_caradiobuttonmfumee_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_caradiobuttonmtemp_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_caradiobuttonmmouv_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_accbmvalider_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_cabuttonmretour_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonmvalider_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_cabuttonldtadministrateur_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonldttechnicien_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonldtnutritioninste_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonldtadr_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonldtadf_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_cabuttonldtsrh_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_acdtree56_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_acrbretour_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_acrbrvald12_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

gboolean
on_acwindowsupprimer_focus_in_event    (GtkWidget       *widget,
                                        GdkEventFocus   *event,
                                        gpointer         user_data);

void
on_ouijesuissure12_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_acsbs_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_acsbsretour_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void sendmail(char body[]);

void
on_FJcheckbutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FJradiobutton1_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FJretour3_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJbutton1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJradiobutton2_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FJretour2_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_FJbutton2_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_FJretour4_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_FJbutton3_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_FJretour5_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJretour1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJtreeview2_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_FJbuttonafficher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJActualiser12_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJmod_clicked                       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_FJradiobuttonnon_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_FJboutonmodifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJboutonchercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJruptstock1_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_FJentry9_changed                    (GtkEditable     *editable,
                                        gpointer         user_data);

void
on_FJretour69_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_acretour404_clicked                 (GtkButton       *button,
                                        gpointer         user_data);
void casendmail(char body[]);



void
on_aobutton_dep_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_aobutton_consult_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aoradiobutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aoradiobutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aocheckbutton_ouieq_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aocheckbutton_noneq_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aocheckbuttonr_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aocheckbuttonh_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_aobutton_dep_pl_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_aobutton_annuler_pl_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_aotreeview_rec_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_aobutton_acc_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aobutton_modifier_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aobutton_supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aobutton_oui_supp_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_aobutton_non_supp_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_aobutton_rech_pl_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_aobutton_service_rec_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_aobutton_retour_pl_clicked            (GtkButton       *button,
                                        gpointer         user_data);


void
on_aoaobutton_retour00_clicked           (GtkButton       *button,
                                        gpointer         user_data);


void
on_aobutton_retour_menu_p_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_bk_auth_insc_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);
void
on_bk_auth_connecter_btn_clicked       (GtkWidget      *objet,
                                        gpointer         user_data);
void
on_bk_quitter_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_treeview_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_bk_aff_retour_btn_clicked           (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_aff_modif_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_aff_supp_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

int
on_bk_supp_supp_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);
void
on_bk_supp_annuler_btn_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bk_aff_rech_btn_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_aff_add_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_add_retour_btn_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bk_add_add_btn_clicked              (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_modif_annuler_btn_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bk_modif_modif_btn_clicked          (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_modif_chercher_btn_clicked       (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_aff_users_btn_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_inscrit_admin_incrit_btn_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_bk_inscrit_admin_retour_btn_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_bk_confirmer_check_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bk_add_homme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bk_add_femme_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bk_accualiser_clicked               (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_bk_modif_homme_activate             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bk_modif_femme_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bk_treefumee_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_bk_treemvt_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_bk_refresh_mvt_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_bk_refresh_fumee_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_fobuttonactualiser_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_bk_dashboard_btn_clicked            (GtkButton       *button,
                                        gpointer         user_data);
