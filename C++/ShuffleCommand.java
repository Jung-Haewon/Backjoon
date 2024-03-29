@@ -1,53 +1,50 @@
package com.discord.bot.commands.musiccommands;

import com.discord.bot.audioplayer.GuildMusicManager;
import com.discord.bot.commands.musiccommands.Fails.ChannelFailStrategy;
import com.discord.bot.service.audioplayer.PlayerManagerService;
import com.sedmelluq.discord.lavaplayer.track.AudioTrack;
import net.dv8tion.jda.api.EmbedBuilder;
import net.dv8tion.jda.api.events.interaction.command.SlashCommandInteractionEvent;

import java.awt.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ShuffleCommand extends MusicPlayerCommand {
    
    public ShuffleCommand(PlayerManagerService playerManagerService, MusicCommandUtils utils) {
        this.playerManagerService = playerManagerService;
        this.utils = utils;
    }

    @Override
    void operate(SlashCommandInteractionEvent event, EmbedBuilder embedBuilder) {
        GuildMusicManager musicManager = playerManagerService.getMusicManager(event);
        List<AudioTrack> trackList = new ArrayList<>(musicManager.scheduler.queue);
        if (trackList.size() > 1) {
            ShuffleCollection(musicManager, trackList);
            embedBuilder.setDescription("Queue shuffled").setColor(Color.GREEN);
        } else {
            embedBuilder.setDescription("Queue size have to be at least two.").setColor(Color.RED);
        }
        event.replyEmbeds(embedBuilder.build()).queue();
    }

    @Override
    boolean isValidState(SlashCommandInteractionEvent event) {
        return utils.isBotAndUserInSameChannel(event);
    }

    @Override
    String getFailDescription() {
        return "Please be in a same voice channel as bot.";
    }

    private void ShuffleCollection(GuildMusicManager musicManager, List<AudioTrack> trackList) {
        Collections.shuffle(trackList);
        musicManager.scheduler.queue.clear();

        for (AudioTrack track : trackList) {
            musicManager.scheduler.queue(track);
        }
    }
}
