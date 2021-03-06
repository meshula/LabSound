// License: BSD 3 Clause
// Copyright (C) 2010, Google Inc. All rights reserved.
// Copyright (C) 2015+, The LabSound Authors. All rights reserved.

#ifndef ChannelMergerNode_h
#define ChannelMergerNode_h

#include "LabSound/core/AudioNode.h"

namespace lab
{

class AudioContext;

class ChannelMergerNode : public AudioNode
{
public:
    ChannelMergerNode(AudioContext& ac, int numberOfInputs = 1);
    virtual ~ChannelMergerNode() = default;

    virtual const char* name() const override { return "ChannelMerger"; }

    void addInputs(int n);

    // AudioNode
    virtual void process(ContextRenderLock &, int bufferSize) override;
    virtual void reset(ContextRenderLock &) override;

    // Called in the audio thread (pre-rendering task) when the number of channels for an input may have changed.
    virtual void checkNumberOfChannelsForInput(ContextRenderLock &, AudioNodeInput *) override;

private:
    virtual double tailTime(ContextRenderLock & r) const override { return 0; }
    virtual double latencyTime(ContextRenderLock & r) const override { return 0; }

    int m_desiredNumberOfOutputChannels = 1;  // default
};

}  // namespace lab

#endif  // ChannelMergerNode_h
