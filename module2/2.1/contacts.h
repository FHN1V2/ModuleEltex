#ifndef CONTACTS_H
#define CONTACTS_H

#define MAX_CONTACTS 100
#define MAX_FIELD_LEN 30
#define MAX_PHONES 5
#define MAX_EMAILS 5
#define MAX_SOCIALS 5
#define MAX_MESSENGERS 5

typedef struct  {
    char phones[MAX_PHONES][MAX_FIELD_LEN];
    int phone_count;
}PhoneList ;

typedef struct  {
    char emails[MAX_EMAILS][MAX_FIELD_LEN];
    int email_count;
} EmailList;

typedef struct  {
    char socials[MAX_SOCIALS][MAX_FIELD_LEN];
    int social_count;
} SocialList;

typedef struct  {
    char messengers[MAX_MESSENGERS][MAX_FIELD_LEN];
    int messenger_count;
}MessengerList;

typedef struct {
    int id; 
    char first_name[MAX_FIELD_LEN]; 
    char last_name[MAX_FIELD_LEN];
    char middle_name[MAX_FIELD_LEN];
    char job[MAX_FIELD_LEN];
    char position[MAX_FIELD_LEN];
    PhoneList phone_list;
    EmailList email_list;
    SocialList social_list;
    MessengerList messenger_list;
} Contact;

extern Contact contacts[MAX_CONTACTS];
extern int contact_count;
extern int next_id;

void add_contact();
void edit_contact(int id);
void delete_contact(int id);
void print_contacts();
int find_contact_by_id(int id);
int find_contact_by_name(const char* first_name, const char* last_name);

#endif