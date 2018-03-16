#include "something"
...
uint8_t * get_key(int u)
{
    uint8_t key_bytes[u];
    int i;
    for(i = 0; i < u; i++)
    {
        *(key_bytes + i) = rand() % 256;
    }

    return key_bytes;
}
int main()
{
    EC_KEY *key;
    uint8_t digest[32];
    ECDSA_SIG *signature;
    uint8_t *der, *der_copy;
    size_t der_len;

    /*Create a symbolic value*/
    int a;
    klee_make_symbolic(&a, sizeof(a), "a");

    /*Get key pair*/
    key = bbp_ec_new_keypair(get_key(a));
    if(!key)
    {
        puts("Unable to create keypair");
        return -1;
    }

    bbp_sha256(digest, (uint8_t *)message, strlen(message));

    signature = ECDSA_do_sign(digest, sizeof(digest), key);
    .
    .
    .
    return 0;
}
