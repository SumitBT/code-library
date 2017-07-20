package swishtech.api.controllers;

import java.util.List;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.Authentication;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import swishtech.api.models.Event;
import swishtech.api.models.User;
import swishtech.api.other.Response;
import swishtech.api.repositories.EventRepo;
import swishtech.api.repositories.UserRepo;

@RestController
public class EventController
{
	
	@Autowired
	private EventRepo eventRepo;
	
	@Autowired
	private UserRepo userRepo;
	
	@ResponseBody
	@RequestMapping(value="/event",method=RequestMethod.GET)
	public Iterable<Event> showAll()
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByEmail(auth.getName());
		if(user.getRoleId()==1||user.getRoleId()==3)
		{
			return eventRepo.findAll();
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/event",method=RequestMethod.POST)
	public Response add(@RequestBody Event event)
	{
		Response response = new Response();
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByEmail(auth.getName());
		if(user.getRoleId()==1)
		{
			event.setAdminId(user.getUserId());
			eventRepo.save(event);
			return response;
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/event/{id}",method=RequestMethod.GET)
	public Event details(@PathVariable long id)
	{
		return eventRepo.findOne(id);
	}
	
	@ResponseBody
	@RequestMapping(value="/event/{id}",method=RequestMethod.PUT)
	public Event update(@PathVariable long id, @RequestBody Event event)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByEmail(auth.getName());
		if(user.getRoleId()==1)
		{
			Event e = eventRepo.findOne(id);
			e.setName(event.getName());
			e.setAccountId(event.getAccountId());
			e.setStartDt(event.getStartDt());
			e.setEndDt(event.getEndDt());
			e.setDescription(event.getDescription());
			e.setLocation(event.getLocation());
			eventRepo.save(e);
			return e;
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/event/account/{accountid}",method=RequestMethod.GET)
	public List<Event> list(@PathVariable long accountid)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByEmail(auth.getName());
		if(user.getRoleId()==1)
		{
			return eventRepo.findByAccountId(accountid);
		}
		else return null;
	}
}
