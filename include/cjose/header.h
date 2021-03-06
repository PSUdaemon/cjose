/*
 * Copyrights
 *
 * Portions created or assigned to Cisco Systems, Inc. are
 * Copyright (c) 2014-2016 Cisco Systems, Inc.  All Rights Reserved.
 */

/**
 * \file
 * \brief
 * Functions and data structures for interacting with
 * JSON Web Signature (JWS) objects.
 *
 */

#ifndef CJOSE_HEADER_H
#define CJOSE_HEADER_H

#include <stdbool.h>
#include "cjose/error.h"

#ifdef __cplusplus
extern "C"
{
#endif


/** The JWE algorithm header attribute name. */
extern const char *CJOSE_HDR_ALG;

/** The JWE content encryption algorithm header attribute name. */
extern const char *CJOSE_HDR_ENC;

/** The JWE "cty" header attribute. */
extern const char *CJOSE_HDR_CTY;

/** The Jose "kid" header attribute. */
extern const char *CJOSE_HDR_KID;

/** The JWA algorithm attribute value for none. */
extern const char *CJOSE_HDR_ALG_NONE;

/** The JWE algorithm attribute value for RSA-OAEP. */
extern const char *CJOSE_HDR_ALG_RSA_OAEP;

/** The JWE algorithm attribute value for RSA1_5. */
extern const char *CJOSE_HDR_ALG_RSA1_5;

/** The JWE algorithm attribute value for A128KW, A192KW and A256KW. */
extern const char *CJOSE_HDR_ALG_A128KW;
extern const char *CJOSE_HDR_ALG_A192KW;
extern const char *CJOSE_HDR_ALG_A256KW;

/** The JWS algorithm attribute value for PS256, PS384 and PS512. */
extern const char *CJOSE_HDR_ALG_PS256;
extern const char *CJOSE_HDR_ALG_PS384;
extern const char *CJOSE_HDR_ALG_PS512;

/** The JWS algorithm attribute value for RS256, RS384 and RS512. */
extern const char *CJOSE_HDR_ALG_RS256;
extern const char *CJOSE_HDR_ALG_RS384;
extern const char *CJOSE_HDR_ALG_RS512;

/** The JWS algorithm attribute values for HS256, HS384 and HS512. */
extern const char *CJOSE_HDR_ALG_HS256;
extern const char *CJOSE_HDR_ALG_HS384;
extern const char *CJOSE_HDR_ALG_HS512;

/** The JWS algorithm attribute values for ES256, ES384 and ES512. */
extern const char *CJOSE_HDR_ALG_ES256;
extern const char *CJOSE_HDR_ALG_ES384;
extern const char *CJOSE_HDR_ALG_ES512;

/** The JWE algorithm attribute value for "dir". */
extern const char *CJOSE_HDR_ALG_DIR;

/** The JWE content encryption algorithm value for A256GCM. */
extern const char *CJOSE_HDR_ENC_A256GCM;

/** The JWE content encryption algorithm value for A128CBC-HS256, A192CBC-HS384 and A256CBC-HS512. */
extern const char *CJOSE_HDR_ENC_A128CBC_HS256;
extern const char *CJOSE_HDR_ENC_A192CBC_HS384;
extern const char *CJOSE_HDR_ENC_A256CBC_HS512;


/**
 * An instance of a header object (used when creating JWE/JWS objects).
 */
typedef struct json_t cjose_header_t;


/**
 * Instsantiates a new header object. Caller is responsible for
 * subsequently releasing the object through cjose_header_release().
 *
 * \param err [out] An optional error object which can be used to get additional
 *        information in the event of an error.
 * \returns a newly allocated header object, or NULL if an error occurs.
 */
cjose_header_t *cjose_header_new(
        cjose_err *err);


/**
 * Retains an existing header object. Callers must use this method if the
 * header will be used past the scope it was created in (e.g., from a
 * `cjose_jws_t` object).
 *
 * \param header[in] the header object to be retained.
 * \returns the retained header object
 */
cjose_header_t *cjose_header_retain(
        cjose_header_t *header);

/**
 * Releases an existing header object. Callers must use this method
 * to dispose of header rather than directly free'ing a cjose_header
 * object.
 *
 * \param header[in] the header object to be released.
 */
void cjose_header_release(
		cjose_header_t *header);


/**
 * Sets a header attribute on a header object.  If that header was
 * previously set, this will replace the previous value with the new one.
 *
 * \param header[in] a previously instantated header object.
 * \param attr[in] the header attribute to be set.
 * \param value[in] the value to assign to the header attribute.
 * \param err [out] An optional error object which can be used to get additional
 *        information in the event of an error.
 * \returns true if header is successfully set.
 */
bool cjose_header_set(
        cjose_header_t *header,
        const char *attr,
        const char *value,
        cjose_err *err);

/**
 * Retrieves the value of the requested header attribute from the header
 * object.
 *
 * \param header[in] a header object.
 * \param attr[in] the header attribute to be got.
 * \param err [out] An optional error object which can be used to get additional
 *        information in the event of an error.
 * \returns a string containing the current value for the requested attribute.
 */
const char *cjose_header_get(
        cjose_header_t *header,
        const char *attr,
        cjose_err *err);


#ifdef __cplusplus
}
#endif

#endif  // CJOSE_HEADER_H
