//***************************************************************************
// Copyright 2017 OceanScan - Marine Systems & Technology, Lda.             *
//***************************************************************************
// Licensed under the Apache License, Version 2.0 (the "License");          *
// you may not use this file except in compliance with the License.         *
// You may obtain a copy of the License at                                  *
//                                                                          *
// http://www.apache.org/licenses/LICENSE-2.0                               *
//                                                                          *
// Unless required by applicable law or agreed to in writing, software      *
// distributed under the License is distributed on an "AS IS" BASIS,        *
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
// See the License for the specific language governing permissions and      *
// limitations under the License.                                           *
//***************************************************************************
// Author: Ricardo Martins                                                  *
//***************************************************************************
// Automatically generated.                                                 *
//***************************************************************************
// IMC XML MD5: 0fe4582bf06b504af601569d6a25a3a2                            *
//***************************************************************************

#ifndef IMC_SESSIONSUBSCRIPTION_HPP_INCLUDED_
#define IMC_SESSIONSUBSCRIPTION_HPP_INCLUDED_

// ISO C++ 98 headers.
#include <ostream>
#include <string>
#include <vector>

// IMC headers.
#include <IMC/Base/Config.hpp>
#include <IMC/Base/Message.hpp>
#include <IMC/Base/InlineMessage.hpp>
#include <IMC/Base/MessageList.hpp>
#include <IMC/Base/JSON.hpp>
#include <IMC/Base/Serialization.hpp>
#include <IMC/Spec/Enumerations.hpp>
#include <IMC/Spec/Bitfields.hpp>

namespace IMC
{
  //! Session Subscription.
  class SessionSubscription: public Message
  {
  public:
    //! Session Identifier.
    uint32_t sessid;
    //! Messages to subscribe.
    std::string messages;

    static uint16_t
    getIdStatic(void)
    {
      return 808;
    }

    static SessionSubscription*
    cast(Message* msg__)
    {
      return (SessionSubscription*)msg__;
    }

    SessionSubscription(void)
    {
      m_header.mgid = SessionSubscription::getIdStatic();
      clear();
    }

    SessionSubscription*
    clone(void) const
    {
      return new SessionSubscription(*this);
    }

    void
    clear(void)
    {
      sessid = 0;
      messages.clear();
    }

    bool
    fieldsEqual(const Message& msg__) const
    {
      const IMC::SessionSubscription& other__ = static_cast<const SessionSubscription&>(msg__);
      if (sessid != other__.sessid) return false;
      if (messages != other__.messages) return false;
      return true;
    }

    uint8_t*
    serializeFields(uint8_t* bfr__) const
    {
      uint8_t* ptr__ = bfr__;
      ptr__ += IMC::serialize(sessid, ptr__);
      ptr__ += IMC::serialize(messages, ptr__);
      return ptr__;
    }

    size_t
    deserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::deserialize(sessid, bfr__, size__);
      bfr__ += IMC::deserialize(messages, bfr__, size__);
      return bfr__ - start__;
    }

    size_t
    reverseDeserializeFields(const uint8_t* bfr__, size_t size__)
    {
      const uint8_t* start__ = bfr__;
      bfr__ += IMC::reverseDeserialize(sessid, bfr__, size__);
      bfr__ += IMC::reverseDeserialize(messages, bfr__, size__);
      return bfr__ - start__;
    }

    uint16_t
    getId(void) const
    {
      return SessionSubscription::getIdStatic();
    }

    const char*
    getName(void) const
    {
      return "SessionSubscription";
    }

    size_t
    getFixedSerializationSize(void) const
    {
      return 4;
    }

    size_t
    getVariableSerializationSize(void) const
    {
      return IMC::getSerializationSize(messages);
    }

    void
    fieldsToJSON(std::ostream& os__, unsigned nindent__) const
    {
      IMC::toJSON(os__, "sessid", sessid, nindent__);
      IMC::toJSON(os__, "messages", messages, nindent__);
    }
  };
}

#endif
