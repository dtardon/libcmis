/* libcmis
 * Version: MPL 1.1 / GPLv2+ / LGPLv2+
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License or as specified alternatively below. You may obtain a copy of
 * the License at http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * Major Contributor(s):
 * Copyright (C) 2011 SUSE <cbosdonnat@suse.com>
 *
 *
 * All Rights Reserved.
 *
 * For minor contributions see the git repository.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPLv2+"), or
 * the GNU Lesser General Public License Version 2 or later (the "LGPLv2+"),
 * in which case the provisions of the GPLv2+ or the LGPLv2+ are applicable
 * instead of those above.
 */
#include "atom-object.hxx"
#include "atom-session.hxx"
#include "atom-utils.hxx"

using namespace std;

/** Constructor for the object, the url provided url should point to the object
    CMIS properties. The content of the URL isn't extracted and parsed by the constructor:
    this task is left to the class children.
  */
AtomCmisObject::AtomCmisObject( AtomPubSession* session, string url ) :
    m_session( session ),
    m_infosUrl( url ),
    m_name( )
{
}

AtomCmisObject::~AtomCmisObject( )
{
}

string AtomCmisObject::getId( )
{
    return m_id;
}

string AtomCmisObject::getName( )
{
    return m_name;
}

void AtomCmisObject::extractInfos( xmlDocPtr doc )
{
    xmlXPathContextPtr pXPathCtx = xmlXPathNewContext( doc );

    // Register the Service Document namespaces
    atom::registerNamespaces( pXPathCtx );

    if ( NULL != pXPathCtx )
    {
        // Get the name
        string nameReq( "//cmis:propertyString[@propertyDefinitionId='cmis:name']/cmis:value/text()" );
        m_name = atom::getXPathValue( pXPathCtx, nameReq );
        
        // Get the id
        string idReq( "//cmis:propertyId[@propertyDefinitionId='cmis:objectId']/cmis:value/text()" );
        m_id = atom::getXPathValue( pXPathCtx, idReq );
    }
    xmlXPathFreeContext( pXPathCtx );
}