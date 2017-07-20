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
import swishtech.api.models.PasswordResetToken;
import swishtech.api.models.User;
import swishtech.api.other.Response;
import swishtech.api.repositories.PasswordResetTokenRepo;
import swishtech.api.repositories.UserRepo;
import swishtech.api.services.MailService;

@RestController
public class SuperControllers
{
	@Autowired
	private UserRepo userRepo;
	
	@Autowired
	private PasswordResetTokenRepo passwordResetTokenRepo;
	
	@Autowired
	private MailService ms;
	
	@ResponseBody
	@RequestMapping(value="/super",method=RequestMethod.GET)
	public Iterable<User> show()
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User user = userRepo.findByEmail(auth.getName());
		if(user.getRoleId()==1)
		{
			Iterable<User> u = userRepo.findByRoleId((long)1);
			return u;
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/super",method=RequestMethod.POST)
	public Response add(@RequestBody User user)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			Response response = new Response();
			user.setPassword("********");
			user.setRoleId(1);
			user.setStatusId(2);
			user.setSignupDt(new Date());
			try
			{
				if(user.getEmail().equals(null)||user.getEmail().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("Email can't be null!");
					return response;
				}
				else if(userRepo.findByEmail(user.getEmail()) != null)
				{
					response.setSuccess(false);
					response.setMessage("Email already Exists!");
					return response;
				}
				else if(user.getFirstName().equals(null)||user.getFirstName().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("FirstName can't be null!");
					return response;
				}
				else if(user.getLastName().equals(null)||user.getLastName().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("LastName can't be null!");
					return response;
				}
				else if(user.getPassword().equals(null)||user.getPassword().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("Password can't be null!");
					return response;
				}
			}catch(Exception e)
			{
				response.setSuccess(false);
				response.setMessage(e.toString());
				return response;
			}
			User u;
			try
			{
				u = userRepo.save(user);
			}catch(Exception e)
			{
				response.setSuccess(false);
				response.setMessage(e.toString());
				return response;
			}
			PasswordResetToken prt = new PasswordResetToken(UUID.randomUUID().toString(), u.getUserId());
			prt.setReset(false);
			passwordResetTokenRepo.save(prt);
			ms.sendPasswordResetMail(u);
			return response;
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/super/{id}",method=RequestMethod.GET)
	public User details(@PathVariable long id)
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
	@RequestMapping(value="/super/{id}",method=RequestMethod.PUT)
	public Response update(@PathVariable long id, @RequestBody User user)
	{
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			Response response = new Response();
			User u = userRepo.findOne(id);
			try
			{
				if(user.getFirstName().equals(null)||user.getFirstName().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("FirstName can't be null!");
					return response;
				}
				else if(user.getLastName().equals(null)||user.getLastName().equals(""))
				{
					response.setSuccess(false);
					response.setMessage("LastName can't be null!");
					return response;
				}
			}catch(Exception e)
			{
				response.setSuccess(false);
				response.setMessage(e.toString());
				return response;
			}
			if(u!=null)
			{
				u.setFirstName(user.getFirstName());
				u.setLastName(user.getLastName());
				userRepo.save(u);
				return response;
			}
			else
			{
				response.setSuccess(false);
				response.setMessage("User doesn't exist!");
				return response;
			}
		}
		else return null;
	}
	
	@ResponseBody
	@RequestMapping(value="/super/{id}",method=RequestMethod.DELETE)
	public Response remove(@PathVariable long id)
	{
		Response response = new Response();
		Authentication auth = SecurityContextHolder.getContext().getAuthentication();
		User u1 = userRepo.findByEmail(auth.getName());
		if(u1.getRoleId()==1)
		{
			userRepo.delete(id);
			return response;
		}
		return null;
	}
}
