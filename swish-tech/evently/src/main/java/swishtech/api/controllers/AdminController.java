package swishtech.api.controllers;

import java.util.Date;
import java.util.UUID;
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
import swishtech.api.models.PasswordResetToken;
import swishtech.api.models.User;
import swishtech.api.repositories.EventRepo;
import swishtech.api.repositories.PasswordResetTokenRepo;
import swishtech.api.repositories.UserRepo;
import swishtech.api.services.MailService;

@RestController
public class AdminController
{
	@Autowired
	private UserRepo userRepo;
	
	@Autowired
	private EventRepo eventRepo;
	
	@Autowired
	private PasswordResetTokenRepo passwordResetTokenRepo;
	
	@Autowired
	private MailService ms;
	
	@ResponseBody
	@RequestMapping(value="/admin",method=RequestMethod.GET)
	public Iterable<User> show()
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByEmail(auth.getName());
		if(user.getRoleId()==1)
		{
			return userRepo.findByRoleId(2);
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/admin/{eventid}",method=RequestMethod.POST)
	public User add(@PathVariable long eventid, @RequestBody User user)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			//validation
			Event e = eventRepo.findOne(eventid);
			user.setPassword("********");
			user.setRoleId(2);
			user.setStatusId(2);
			user.setSignupDt(new Date());
			User u = userRepo.save(user);
			e.setAdminId(u.getUserId());
			eventRepo.save(e);
			PasswordResetToken prt = new PasswordResetToken(UUID.randomUUID().toString(), u.getUserId());
			prt.setReset(false);
			passwordResetTokenRepo.save(prt);
			ms.sendPasswordResetMail(u);
			return u;
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/admin/{id}",method=RequestMethod.GET)
	public User  details(@PathVariable long id)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			return userRepo.findOne(id);
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/admin/{id}",method=RequestMethod.PUT)
	public User update(@PathVariable long id, @RequestBody User user)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			User u = userRepo.findOne(id);
			u.setFirstName(user.getFirstName());
			u.setLastName(user.getLastName());
			userRepo.save(u);
			return u;
		}
		else return null;
	}
}
